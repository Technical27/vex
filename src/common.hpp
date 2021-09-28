#include "main.h"

#include <cstdio>

using namespace okapi;

extern std::shared_ptr<ChassisController> chassis;
extern Controller controller;

#include "display.hpp"

#ifdef COMMON_DEFINE

std::shared_ptr<ChassisController> chassis =
    ChassisControllerBuilder()
        .withMotors({-2, -4, -6}, {1, 3, 5})
        .withDimensions(AbstractMotor::gearset::green,
                        {{4_in, 11.5_in}, imev5GreenTPR})
        .build();
Controller controller(ControllerId::master);

#endif // COMMON_DEFINE
