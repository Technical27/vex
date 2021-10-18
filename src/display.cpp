#include "display.hpp"

void DisplayManager::updateLabels(float left, float right) {
  lv_gauge_set_value(controllerLeftGauge, 0, left * 100);
  lv_gauge_set_value(controllerRightGauge, 0, right * 100);
}

DisplayManager::DisplayManager() {
  lv_obj_t *scr = lv_scr_act();

  controllerLeftLabel = lv_label_create(scr, nullptr);
  lv_label_set_align(controllerLeftLabel, LV_LABEL_ALIGN_LEFT);
  lv_obj_set_pos(controllerLeftLabel, 0, 50);
  lv_label_set_text(controllerLeftLabel, "Controller Left");

  controllerLeftGauge = lv_gauge_create(scr, nullptr);
  lv_obj_set_pos(controllerLeftGauge, 0, 80);
  lv_gauge_set_range(controllerLeftGauge, -100, 100);
  lv_obj_set_width(controllerLeftGauge, 200);
  lv_gauge_set_critical_value(controllerLeftGauge, 100);

  controllerRightLabel = lv_label_create(scr, nullptr);
  lv_label_set_align(controllerRightLabel, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(controllerRightLabel, "Controller Right");
  lv_obj_set_pos(controllerRightLabel, 70, 50);

  controllerRightGauge = lv_gauge_create(scr, nullptr);
  lv_gauge_set_range(controllerRightGauge, -100, 100);
  lv_obj_set_pos(controllerRightGauge, 270, 80);
  lv_obj_set_width(controllerRightGauge, 200);
  lv_gauge_set_critical_value(controllerRightGauge, 100);

  mainLabel = lv_label_create(scr, nullptr);
  lv_obj_align(mainLabel, scr, LV_ALIGN_IN_TOP_LEFT, 0, 0);
  lv_label_set_text(mainLabel, "Super Helpful Informational Thing");
}

DisplayManager::~DisplayManager() {
  if (controllerLeftLabel != nullptr) {
    lv_obj_del(controllerLeftLabel);
  }
  if (controllerRightLabel != nullptr) {
    lv_obj_del(controllerRightLabel);
  }
}
