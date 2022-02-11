#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

class Paw
{
public:
    Paw() = default;
    Paw(Adafruit_PWMServoDriver driver, uint8_t servoGround, uint8_t servoMiddle, uint8_t servoRobot);

    void setDefaultPosition();
    void setAll(int angle);
    void setAll(int angleGround, int angleMiddle, int angleRobot);
    void setServoRobot(int angle);
    void setServoMiddle(int angle);
    void setServoGround(int angle);
    void up();
    void down();
    void left();
    void right();
    
private:
    Adafruit_PWMServoDriver _driver;
    uint8_t _servoGround;
    uint8_t _servoMiddle;
    uint8_t _servoRobot;

    int getPulseFromAngle(int angle);
};
