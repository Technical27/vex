#include "display.hpp"

void DisplayManager::updateLabels(float left, float right) {
  snprintf(leftLabelText, 32, "Controller Left: %.2f", left * 100);
  snprintf(rightLabelText, 32, "Controller Right: %.2f", right * 100);

  lv_label_set_text(controllerLeftLabel, leftLabelText);
  lv_label_set_text(controllerRightLabel, rightLabelText);
}

void DisplayManager::initDisplay() {
  controllerLeftLabel = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_align(controllerLeftLabel, LV_LABEL_ALIGN_LEFT);
  lv_obj_set_pos(controllerLeftLabel, 0, 0);

  controllerRightLabel = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_align(controllerRightLabel, LV_LABEL_ALIGN_LEFT);
  lv_obj_set_pos(controllerLeftLabel, 0, 20);
}

DisplayManager::~DisplayManager() {
  if (controllerLeftLabel != nullptr) {
    lv_obj_del(controllerLeftLabel);
  }
  if (controllerRightLabel != nullptr) {
    lv_obj_del(controllerRightLabel);
  }
}
