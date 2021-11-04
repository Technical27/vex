#define COMMON_DEFINE
#include "common.hpp"

std::shared_ptr<DisplayManager> displayManager;

void initialize() {
  displayManager = std::make_shared<DisplayManager>(DisplayManager());
  liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  liftController->tarePosition();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
  // slow down everything
  /* chassis->setMaxVelocity(80); */
  /* liftController->setMaxVelocity(100); */
  /* chassis->getModel()->resetSensors(); */
  /* liftController->tarePosition(); */

  // move forward and drop the lift
  /* chassis->moveRaw(2050); */
  /* liftController->setTarget(-700); */
  /* liftController->waitUntilSettled(); */

  // move back and have the ring catch on the edge
  /* chassis->moveRaw(-900); */

  // put lift down fully
  liftController->setTarget(-900);

  // turn left, move forward, turn right and push the mobile goal
  /* chassis->turnRaw(200); */
  /* liftController->waitUntilSettled(); */
  /* chassis->moveRaw(1200); */
  /* chassis->turnRaw(500); */
  /* chassis->moveRaw(200); */
  /* chassis->moveRaw(-1000); */

  // restore max velocity
  /* chassis->setMaxVelocity(600); */
  /* liftController->setMaxVelocity(600); */
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
