#include "devices.hpp"
#include "constants.hpp"

std::shared_ptr<ChassisController> chassis =
    ChassisControllerBuilder()
        .withMotors({FRONT_LEFT_MOTOR, BACK_LEFT_MOTOR},
                    {FRONT_RIGHT_MOTOR, BACK_RIGHT_MOTOR})
        .withDimensions(AbstractMotor::gearset::green,
                        {{WHEEL_DIAMETER, TRACK_WIDTH}, imev5GreenTPR})
        .build();

MotorGroup liftMotor({
    RIGHT_LIFT_MOTOR,
    LEFT_LIFT_MOTOR,
});

std::shared_ptr<AsyncPositionController<double, double>> liftController =
    AsyncPosControllerBuilder().withMotor(liftMotor).build();

Controller controller(ControllerId::master);
