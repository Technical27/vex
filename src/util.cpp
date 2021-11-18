#include "util.hpp"

namespace util {

namespace pcfs {
namespace {
typedef FILE *pc_file_t;

lv_fs_res_t open(void *file_p, const char *fn, lv_fs_mode_t mode) {
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

lv_fs_res_t close(void *file_p) {
  pc_file_t *fp = (pc_file_t *)file_p;
  fclose(*fp);
  return LV_FS_RES_OK;
}

lv_fs_res_t read(void *file_p, void *buf, uint32_t btr, uint32_t *br) {
  pc_file_t *fp = (pc_file_t *)file_p;
  *br = fread(buf, 1, btr, *fp);
  return LV_FS_RES_OK;
}

lv_fs_res_t seek(void *file_p, uint32_t pos) {
  pc_file_t *fp = (pc_file_t *)file_p;
  fseek(*fp, pos, SEEK_SET);
  return LV_FS_RES_OK;
}

lv_fs_res_t tell(void *file_p, uint32_t *pos_p) {
  pc_file_t *fp = (pc_file_t *)file_p;
  *pos_p = ftell(*fp);
  return LV_FS_RES_OK;
}
} // namespace
void init() {
  lv_fs_drv_t pcfs_drv;                      /*A driver descriptor*/
  memset(&pcfs_drv, 0, sizeof(lv_fs_drv_t)); /*Initialization*/

  pcfs_drv.file_size = sizeof(pc_file_t); /*Set up fields...*/
  pcfs_drv.letter = 'S';
  pcfs_drv.open = pcfs::open;
  pcfs_drv.close = pcfs::close;
  pcfs_drv.read = pcfs::read;
  pcfs_drv.seek = pcfs::seek;
  pcfs_drv.tell = pcfs::tell;
  lv_fs_add_drv(&pcfs_drv);
}

} // namespace pcfs
void logger() {
  FILE *f = fopen("/usd/log.txt", "a+");
  Logger::setDefaultLogger(std::make_shared<Logger>(std::make_unique<Timer>(),
                                                    f, Logger::LogLevel::info));
}
} // namespace util
