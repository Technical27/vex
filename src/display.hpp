#include "main.h"
#include "util.hpp"

class DisplayManager {
public:
  DisplayManager();
  DisplayManager(DisplayManager &&) = default;
  DisplayManager(const DisplayManager &) = default;
  DisplayManager &operator=(DisplayManager &&) = default;
  DisplayManager &operator=(const DisplayManager &) = default;
  ~DisplayManager();

  void updateLabels(float left, float right);

private:
  lv_obj_t *controllerLeftLabel;
  lv_obj_t *controllerRightLabel;

  lv_obj_t *controllerLeftGauge;
  lv_obj_t *controllerRightGauge;

  lv_obj_t *mainLabel;

  char leftLabelText[32];
  char rightLabelText[32];
};
