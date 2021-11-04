#include "display.hpp"

typedef FILE *pc_file_t;

static lv_fs_res_t pcfs_open(void *file_p, const char *fn, lv_fs_mode_t mode) {
  errno = 0;
  const char *flags = "";
  if (mode == LV_FS_MODE_WR)
    flags = "wb";
  else if (mode == LV_FS_MODE_RD)
    flags = "rb";
  else if (mode == (LV_FS_MODE_WR | LV_FS_MODE_RD))
    flags = "a+";

  char buf[256];
  sprintf(buf, "/%s", fn);
  pc_file_t f = fopen(buf, flags);

  if (f == NULL)
    return LV_FS_RES_UNKNOWN;
  else {
    fseek(f, 0, SEEK_SET);
    pc_file_t *fp = (pc_file_t *)file_p;
    *fp = f;
  }

  return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_close(void *file_p) {
  pc_file_t *fp = (pc_file_t *)file_p;
  fclose(*fp);
  return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_read(void *file_p, void *buf, uint32_t btr,
                             uint32_t *br) {
  pc_file_t *fp = (pc_file_t *)file_p;
  *br = fread(buf, 1, btr, *fp);
  return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_seek(void *file_p, uint32_t pos) {
  pc_file_t *fp = (pc_file_t *)file_p;
  fseek(*fp, pos, SEEK_SET);
  return LV_FS_RES_OK;
}

static lv_fs_res_t pcfs_tell(void *file_p, uint32_t *pos_p) {
  pc_file_t *fp = (pc_file_t *)file_p;
  *pos_p = ftell(*fp);
  return LV_FS_RES_OK;
}

void initFsDriver() {
  lv_fs_drv_t pcfs_drv;                      /*A driver descriptor*/
  memset(&pcfs_drv, 0, sizeof(lv_fs_drv_t)); /*Initialization*/

  pcfs_drv.file_size = sizeof(pc_file_t); /*Set up fields...*/
  pcfs_drv.letter = 'S';
  pcfs_drv.open = pcfs_open;
  pcfs_drv.close = pcfs_close;
  pcfs_drv.read = pcfs_read;
  pcfs_drv.seek = pcfs_seek;
  pcfs_drv.tell = pcfs_tell;
  lv_fs_add_drv(&pcfs_drv);
}

void DisplayManager::updateLabels(float left, float right) {
  /* lv_gauge_set_value(controllerLeftGauge, 0, left * 100); */
  /* lv_gauge_set_value(controllerRightGauge, 0, right * 100); */
}

DisplayManager::DisplayManager() {
  initFsDriver();
  lv_obj_t *scr = lv_scr_act();

  lv_obj_t *img_var = lv_img_create(scr, nullptr);
  lv_img_set_src(img_var, "S:/usd/obama.bin");
  /* lv_img_set_auto_size(img_var, true); */
  /* lv_obj_set_size(img_var, LV_HOR_RES, LV_VER_RES); */
  lv_obj_align(img_var, scr, LV_ALIGN_CENTER, 0, 0);
  /* lv_obj_set_pos(img_var, 0, 0); */

  /* controllerLeftLabel = lv_label_create(scr, nullptr); */
  /* lv_label_set_align(controllerLeftLabel, LV_LABEL_ALIGN_LEFT); */
  /* lv_obj_set_pos(controllerLeftLabel, 0, 50); */
  /* lv_label_set_text(controllerLeftLabel, "Controller Left"); */

  /* controllerLeftGauge = lv_gauge_create(scr, nullptr); */
  /* lv_obj_set_pos(controllerLeftGauge, 0, 80); */
  /* lv_gauge_set_range(controllerLeftGauge, -100, 100); */
  /* lv_obj_set_width(controllerLeftGauge, 200); */
  /* lv_gauge_set_critical_value(controllerLeftGauge, 100); */

  /* controllerRightLabel = lv_label_create(scr, nullptr); */
  /* lv_label_set_align(controllerRightLabel, LV_LABEL_ALIGN_LEFT); */
  /* lv_label_set_text(controllerRightLabel, "Controller Right"); */
  /* lv_obj_set_pos(controllerRightLabel, 70, 50); */

  /* controllerRightGauge = lv_gauge_create(scr, nullptr); */
  /* lv_gauge_set_range(controllerRightGauge, -100, 100); */
  /* lv_obj_set_pos(controllerRightGauge, 270, 80); */
  /* lv_obj_set_width(controllerRightGauge, 200); */
  /* lv_gauge_set_critical_value(controllerRightGauge, 100); */

  /* mainLabel = lv_label_create(scr, nullptr); */
  /* lv_obj_align(mainLabel, scr, LV_ALIGN_IN_TOP_LEFT, 0, 0); */
  /* lv_label_set_text(mainLabel, "Super Helpful Informational Thing"); */
}

DisplayManager::~DisplayManager() {
  /* if (controllerLeftLabel != nullptr) { */
  /*   lv_obj_del(controllerLeftLabel); */
  /* } */
  /* if (controllerRightLabel != nullptr) { */
  /*   lv_obj_del(controllerRightLabel); */
  /* } */
}
