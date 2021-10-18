#define COMMON_DEFINE
#include "common.hpp"

std::shared_ptr<DisplayManager> displayManager;

void initialize() {
  displayManager = std::make_shared<DisplayManager>(DisplayManager());
  liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  /* std::shared_ptr<XDriveModel> model = */
  /*     std::dynamic_pointer_cast<XDriveModel,
   * ChassisModel>(chassis->getModel()); */

  // push the mobile goal
  liftMotor.moveRelative(-1000, -6000);
  /* pros::delay(3000); */
  /* chassis->moveRaw(20000); */

  /* chassis->moveRaw(-4500); */

  /* model->strafe(-1); */
  /* pros::delay(500); */
  /* model->stop(); */

  /* liftMotor.moveRelative(-1000, -6000); */
}

void opcontrol() {
  /* std::shared_ptr<XDriveModel> model = */
  /*     std::dynamic_pointer_cast<XDriveModel,
   * ChassisModel>(chassis->getModel()); */
  std::shared_ptr<ChassisModel> model = chassis->getModel();

  while (true) {
    float leftY = controller.getAnalog(ControllerAnalog::leftY);
    float rightY = controller.getAnalog(ControllerAnalog::rightY);

    model->tank(leftY, rightY);

    displayManager->updateLabels(leftY, rightY);

    if (controller.getDigital(ControllerDigital::L2)) {
      // move lift down
      liftMotor.moveVoltage(-6000);
    } else if (controller.getDigital(ControllerDigital::L1)) {
      // move lift up
      liftMotor.moveVoltage(6000);
    } else {
      liftMotor.moveVoltage(0);
    }

    /* if (controller.getDigital(ControllerDigital::left)) { */
    /*   model->strafe(1); */
    /* } else if (controller.getDigital(ControllerDigital::right)) { */
    /*   model->strafe(-1); */
    /* } */

    pros::delay(20);
  }
}
