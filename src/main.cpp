#define COMMON_DEFINE
#include "common.hpp"

std::shared_ptr<DisplayManager> displayManager =
    std::make_shared<DisplayManager>(DisplayManager());

void initialize() { displayManager->initDisplay(); }

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
  std::shared_ptr<ChassisModel> model = chassis->getModel();

  while (true) {
    float leftY = controller.getAnalog(ControllerAnalog::leftY);
    float rightY = controller.getAnalog(ControllerAnalog::rightY);

    model->tank(leftY, rightY);

    displayManager->updateLabels(leftY, rightY);

    pros::delay(20);
  }
}
