#include "display.hpp"

#define IMAGE_FILE "/usd/obama.bin"

DisplayManager::DisplayManager() {
  util::pcfs::init();
  lv_obj_t *scr = lv_scr_act();

  FILE *f;
  if ((f = fopen(IMAGE_FILE, "r"))) {
    fclose(f);
    lv_obj_t *obama_image = lv_img_create(scr, nullptr);
    lv_img_set_src(obama_image, "S:" IMAGE_FILE);
    lv_obj_align(obama_image, scr, LV_ALIGN_CENTER, 0, 0);
  } else {
    lv_obj_t *no_image_label = lv_label_create(scr, nullptr);
    const char *no_image_text = "404 Image Not Found";
    lv_label_set_text(no_image_label, no_image_text);
    lv_obj_set_width(no_image_label, LV_VER_RES);
    lv_obj_set_height(no_image_label, LV_HOR_RES / 3);
    lv_obj_align(no_image_label, scr, LV_ALIGN_CENTER, 0, 0);
  }
}

DisplayManager::~DisplayManager() {}
