#include "Paw.hpp"

#define SERVOMIN 110
#define SERVOMAX 490

#define DEFAULT_ANGLE_GROUND 150
#define DEFAULT_ANGLE_MIDDLE 45
#define DEFAULT_ANGLE_ROBOT 90

Paw::Paw(Adafruit_PWMServoDriver driver, uint8_t servoGround, uint8_t servoMiddle, uint8_t servoRobot)
    : _driver(driver)
    , _servoGround(servoGround)
    , _servoMiddle(servoMiddle)
    , _servoRobot(servoRobot)
{
    setDefaultPosition();
}

void Paw::setDefaultPosition()
{
    setServoRobot(DEFAULT_ANGLE_ROBOT);
    setServoMiddle(DEFAULT_ANGLE_MIDDLE);
    setServoGround(DEFAULT_ANGLE_GROUND);
}

void Paw::setAll(int angle)
{
    setServoRobot(angle);
    setServoMiddle(angle);
    setServoGround(angle);
}

void Paw::setAll(int angleGround, int angleMiddle, int angleRobot)
{
    setServoRobot(angleRobot);
    setServoMiddle(angleMiddle);
    setServoGround(angleGround);
}

void Paw::setServoRobot(int angle)
{
    _driver.setPWM(_servoRobot, 0, getPulseFromAngle(angle));
}

void Paw::setServoMiddle(int angle)
{
    _driver.setPWM(_servoMiddle, 0, getPulseFromAngle(angle));
}

void Paw::setServoGround(int angle)
{
    _driver.setPWM(_servoGround, 0, getPulseFromAngle(angle));
}

void Paw::up()
{
    setServoMiddle(5);
    setServoGround(100);
}

void Paw::down()
{
    setServoMiddle(DEFAULT_ANGLE_MIDDLE + 10);
    setServoGround(DEFAULT_ANGLE_GROUND);
}

void Paw::left()
{
    setServoRobot(110);
}

void Paw::right()
{
    setServoRobot(70);
}

int Paw::getPulseFromAngle(int angle)
{
    return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}
