#include "common.hpp"

extern std::shared_ptr<ChassisController> chassis;
extern MotorGroup mainLift;
extern MotorGroup auxLift;
extern Controller controller;
extern std::shared_ptr<AsyncPositionController<double, double>>
    mainLiftController;
