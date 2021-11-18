#include "display.hpp"

DisplayManager::DisplayManager() {
  util::pcfs::init();
  lv_obj_t *scr = lv_scr_act();

  lv_obj_t *img_var = lv_img_create(scr, nullptr);
  lv_img_set_src(img_var, "S:/usd/obama.bin");
  lv_obj_align(img_var, scr, LV_ALIGN_CENTER, 0, 0);
}

DisplayManager::~DisplayManager() {}
