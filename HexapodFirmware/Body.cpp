#include "Body.hpp"

#define FREQUENCY 60

#define SERV_FL_GROUND 0
#define SERV_FL_MIDDLE 1
#define SERV_FL_ROBOT 2

#define SERV_FR_GROUND 15
#define SERV_FR_MIDDLE 14
#define SERV_FR_ROBOT 13

#define SERV_ML_GROUND 6
#define SERV_ML_MIDDLE 5
#define SERV_ML_ROBOT 4

#define SERV_MR_GROUND 9
#define SERV_MR_MIDDLE 10
#define SERV_MR_ROBOT 11

#define SERV_BL_GROUND 14
#define SERV_BL_MIDDLE 13
#define SERV_BL_ROBOT 12

#define SERV_BR_GROUND 1
#define SERV_BR_MIDDLE 2
#define SERV_BR_ROBOT 3

#define SLEEP_LONG 150
#define SLEEP_SHORT 75

Body::Body()
    :  _pawFrontLeft()
    , _pawFrontRight()
    , _pawMiddleLeft()
    , _pawMiddleRight()
    , _pawBackLeft()
    , _pawBackRight()
{
    Adafruit_PWMServoDriver pwmLeft = Adafruit_PWMServoDriver(0x40);
    Adafruit_PWMServoDriver pwmRight = Adafruit_PWMServoDriver(0x41);

    pwmLeft.begin();
    pwmLeft.setPWMFreq(FREQUENCY);

    pwmRight.begin();
    pwmRight.setPWMFreq(FREQUENCY);

    _pawFrontLeft = Paw(pwmLeft, SERV_FL_GROUND, SERV_FL_MIDDLE, SERV_FL_ROBOT);
    _pawFrontRight = Paw(pwmRight, SERV_FR_GROUND, SERV_FR_MIDDLE, SERV_FR_ROBOT);
    _pawMiddleLeft = Paw(pwmLeft, SERV_ML_GROUND, SERV_ML_MIDDLE, SERV_ML_ROBOT);
    _pawMiddleRight = Paw(pwmRight, SERV_MR_GROUND, SERV_MR_MIDDLE, SERV_MR_ROBOT);
    _pawBackLeft = Paw(pwmLeft, SERV_BL_GROUND, SERV_BL_MIDDLE, SERV_BL_ROBOT);
    _pawBackRight = Paw(pwmRight, SERV_BR_GROUND, SERV_BR_MIDDLE, SERV_BR_ROBOT);
}

unsigned long Body::getTimeout() const
{
    return SLEEP_SHORT * 2 + SLEEP_LONG * 4;
}

void Body::moveForward()
{
    _pawFrontRight.down();
    _pawBackRight.down();
    _pawMiddleLeft.down();

    delay(SLEEP_SHORT);

    _pawFrontLeft.up();
    _pawBackLeft.up();
    _pawMiddleRight.up();

    delay(SLEEP_LONG);

    _pawFrontRight.right();
    _pawBackRight.right();
    _pawMiddleLeft.left();

    _pawFrontLeft.right();
    _pawBackLeft.right();
    _pawMiddleRight.left();

    delay(SLEEP_LONG);

    _pawFrontLeft.down();
    _pawBackLeft.down();
    _pawMiddleRight.down();

    delay(SLEEP_SHORT);

    _pawFrontRight.up();
    _pawBackRight.up();
    _pawMiddleLeft.up();

    delay(SLEEP_LONG);

    _pawFrontLeft.left();
    _pawBackLeft.left();
    _pawMiddleRight.right();

    _pawFrontRight.left();
    _pawBackRight.left();
    _pawMiddleLeft.right();

    delay(SLEEP_LONG);
}

void Body::moveBackward()
{
    _pawFrontRight.down();
    _pawBackRight.down();
    _pawMiddleLeft.down();

    delay(SLEEP_SHORT);

    _pawFrontLeft.up();
    _pawBackLeft.up();
    _pawMiddleRight.up();

    delay(SLEEP_LONG);

    _pawFrontRight.left();
    _pawBackRight.left();
    _pawMiddleLeft.right();

    _pawFrontLeft.left();
    _pawBackLeft.left();
    _pawMiddleRight.right();

    delay(SLEEP_LONG);

    _pawFrontLeft.down();
    _pawBackLeft.down();
    _pawMiddleRight.down();

    delay(SLEEP_SHORT);

    _pawFrontRight.up();
    _pawBackRight.up();
    _pawMiddleLeft.up();

    delay(SLEEP_LONG);

    _pawFrontLeft.right();
    _pawBackLeft.right();
    _pawMiddleRight.left();

    _pawFrontRight.right();
    _pawBackRight.right();
    _pawMiddleLeft.left();

    delay(SLEEP_LONG);
}

void Body::turnLeft()
{
    _pawFrontRight.down();
    _pawBackRight.down();
    _pawMiddleLeft.down();

    delay(SLEEP_SHORT);

    _pawFrontLeft.up();
    _pawBackLeft.up();
    _pawMiddleRight.up();

    delay(SLEEP_LONG);

    _pawFrontRight.right();
    _pawBackRight.right();
    _pawMiddleLeft.right();

    _pawFrontLeft.left();
    _pawBackLeft.left();
    _pawMiddleRight.left();

    delay(SLEEP_LONG);

    _pawFrontLeft.down();
    _pawBackLeft.down();
    _pawMiddleRight.down();

    delay(SLEEP_SHORT);

    _pawFrontRight.up();
    _pawBackRight.up();
    _pawMiddleLeft.up();

    delay(SLEEP_LONG);

    _pawFrontLeft.right();
    _pawBackLeft.right();
    _pawMiddleRight.right();

    _pawFrontRight.left();
    _pawBackRight.left();
    _pawMiddleLeft.left();

    delay(SLEEP_LONG);
}

void Body::turnRight()
{
    _pawFrontRight.down();
    _pawBackRight.down();
    _pawMiddleLeft.down();

    delay(SLEEP_SHORT);

    _pawFrontLeft.up();
    _pawBackLeft.up();
    _pawMiddleRight.up();

    delay(SLEEP_LONG);

    _pawFrontRight.left();
    _pawBackRight.left();
    _pawMiddleLeft.left();

    _pawFrontLeft.right();
    _pawBackLeft.right();
    _pawMiddleRight.right();

    delay(SLEEP_LONG);

    _pawFrontLeft.down();
    _pawBackLeft.down();
    _pawMiddleRight.down();

    delay(SLEEP_SHORT);

    _pawFrontRight.up();
    _pawBackRight.up();
    _pawMiddleLeft.up();

    delay(SLEEP_LONG);

    _pawFrontLeft.left();
    _pawBackLeft.left();
    _pawMiddleRight.left();

    _pawFrontRight.right();
    _pawBackRight.right();
    _pawMiddleLeft.right();

    delay(SLEEP_LONG);
}

void Body::reset()
{
    _pawFrontLeft.setDefaultPosition();
    _pawFrontRight.setDefaultPosition();
    _pawMiddleLeft.setDefaultPosition();
    _pawMiddleRight.setDefaultPosition();
    _pawBackLeft.setDefaultPosition();
    _pawBackRight.setDefaultPosition();
}
