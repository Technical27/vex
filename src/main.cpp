#include "main.hpp"

std::shared_ptr<DisplayManager> displayManager;

void initialize() {
  util::logger();
  displayManager = std::make_shared<DisplayManager>(DisplayManager());
  mainLift.setBrakeMode(AbstractMotor::brakeMode::hold);
  mainLift.setGearing(AbstractMotor::gearset::red);
  mainLift.setEncoderUnits(AbstractMotor::encoderUnits::degrees);
  mainLiftController->tarePosition();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  // Just put down the lift for now
  mainLiftController->setTarget(MAIN_LIFT_TARGET_DOWN);
}

void opcontrol() {
  std::shared_ptr<ChassisModel> model = chassis->getModel();
  std::uint32_t liftSpeed = MOTOR_MAX_VOLTAGE / 2;
  bool slow = false;

  while (true) {
    float leftY = controller.getAnalog(ControllerAnalog::leftY);
    float rightY = controller.getAnalog(ControllerAnalog::rightY);

    if (controller[ControllerDigital::X].changedToPressed()) {
      controller.rumble(".");
      slow = !slow;
    }

    if (slow) {
      model->tank(leftY * 0.5, rightY * 0.5);
    } else {
      model->tank(leftY, rightY);
    }

    if (controller.getDigital(ControllerDigital::L2)) {
      // move lift down
      mainLift.moveVoltage(-liftSpeed);
    } else if (controller.getDigital(ControllerDigital::L1)) {
      // move lift up
      mainLift.moveVoltage(liftSpeed);
    } else {
      mainLift.moveVoltage(0);
    }

    if (controller.getDigital(ControllerDigital::R2)) {
      // move lift down
      auxLift.moveVoltage(-liftSpeed);
    } else if (controller.getDigital(ControllerDigital::R1)) {
      // move lift up
      auxLift.moveVoltage(liftSpeed);
    } else {
      auxLift.moveVoltage(0);
    }

    pros::delay(20);
  }
}
