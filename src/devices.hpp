#include "common.hpp"

extern std::shared_ptr<ChassisController> chassis;
extern MotorGroup liftMotor;
extern Controller controller;
extern std::shared_ptr<AsyncPositionController<double, double>> liftController;
