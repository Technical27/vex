#include "main.h"

#include <cstdio>

using namespace okapi;

extern std::shared_ptr<ChassisController> chassis;
extern MotorGroup liftMotor;

extern Controller controller;

#include "display.hpp"

pros::ADIDigitalOut piston('a');

#ifdef COMMON_DEFINE

std::shared_ptr<ChassisController> chassis =
    ChassisControllerBuilder()
        .withMotors({-4, -2}, {3, 1})
        .withDimensions(AbstractMotor::gearset::green,
                        {{4_in, 11.5_in}, imev5GreenTPR})
        .build();

MotorGroup liftMotor({
    -11,
    12,
});

std::shared_ptr<AsyncPositionController<double, double>> liftController =
    AsyncPosControllerBuilder().withMotor(liftMotor).build();

Controller controller(ControllerId::master);

#endif // COMMON_DEFINE
