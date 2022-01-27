#include "devices.hpp"
#include "constants.hpp"

std::shared_ptr<ChassisController> chassis =
    ChassisControllerBuilder()
        .withMotors({FRONT_LEFT_MOTOR, BACK_LEFT_MOTOR},
                    {FRONT_RIGHT_MOTOR, BACK_RIGHT_MOTOR})
        .withDimensions(AbstractMotor::gearset::green,
                        {{WHEEL_DIAMETER, TRACK_WIDTH}, imev5GreenTPR})
        .build();

MotorGroup mainLift({
    RIGHT_MAIN_LIFT_MOTOR,
    LEFT_MAIN_LIFT_MOTOR,
});

MotorGroup auxLift({
    RIGHT_AUX_LIFT_MOTOR,
    LEFT_AUX_LIFT_MOTOR,
});

std::shared_ptr<AsyncPositionController<double, double>> mainLiftController =
    AsyncPosControllerBuilder().withMotor(mainLift).build();

std::shared_ptr<AsyncPositionController<double, double>> auxLiftController =
    AsyncPosControllerBuilder().withMotor(auxLift).build();

Controller controller(ControllerId::master);
