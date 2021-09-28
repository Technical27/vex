#include "main.h"

class DisplayManager {
public:
  DisplayManager() = default;
  DisplayManager(DisplayManager &&) = default;
  DisplayManager(const DisplayManager &) = default;
  DisplayManager &operator=(DisplayManager &&) = default;
  DisplayManager &operator=(const DisplayManager &) = default;
  ~DisplayManager();

  void updateLabels(float left, float right);
  void initDisplay();

private:
  lv_obj_t *controllerLeftLabel;
  lv_obj_t *controllerRightLabel;

  char leftLabelText[32];
  char rightLabelText[32];
};
