#include "main.hpp"

std::shared_ptr<DisplayManager> displayManager;

void initialize() {
  util::logger();
  displayManager = std::make_shared<DisplayManager>(DisplayManager());
  liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  liftMotor.setGearing(AbstractMotor::gearset::red);
  liftMotor.setEncoderUnits(AbstractMotor::encoderUnits::degrees);
  liftController->tarePosition();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  // Just put down the lift for now
  liftController->setTarget(LIFT_TARGET_DOWN);
}

void opcontrol() {
  std::shared_ptr<ChassisModel> model = chassis->getModel();
  std::uint32_t liftSpeed = MOTOR_MAX_VOLTAGE / 2;

  while (true) {
    float leftY = controller.getAnalog(ControllerAnalog::leftY);
    float rightY = controller.getAnalog(ControllerAnalog::rightY);

    model->tank(leftY, rightY);

    if (controller.getDigital(ControllerDigital::L2)) {
      // move lift down
      liftMotor.moveVoltage(-liftSpeed);
    } else if (controller.getDigital(ControllerDigital::L1)) {
      // move lift up
      liftMotor.moveVoltage(liftSpeed);
    } else {
      liftMotor.moveVoltage(0);
    }

    pros::delay(20);
  }
}
