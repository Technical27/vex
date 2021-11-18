#define COMMON_DEFINE
#include "common.hpp"

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
  liftController->setTarget(-800);
}

void opcontrol() {
  std::shared_ptr<ChassisModel> model = chassis->getModel();

  while (true) {
    float leftY = controller.getAnalog(ControllerAnalog::leftY);
    float rightY = controller.getAnalog(ControllerAnalog::rightY);

    model->tank(leftY, rightY);

    // testing pneumatics
    piston.set_value(controller.getDigital(ControllerDigital::R1));

    if (controller.getDigital(ControllerDigital::L2)) {
      // move lift down
      liftMotor.moveVoltage(-6000);
    } else if (controller.getDigital(ControllerDigital::L1)) {
      // move lift up
      liftMotor.moveVoltage(6000);
    } else {
      liftMotor.moveVoltage(0);
    }

    pros::delay(20);
  }
}
