#pragma once

#include "Paw.hpp"

class Body
{
    public:
        Body();
        void moveForward();
        void moveBackward();
        void turnLeft();
        void turnRight();
        void reset();

    private:
        Paw _pawFrontLeft;
        Paw _pawFrontRight;
        Paw _pawMiddleLeft;
        Paw _pawMiddleRight;
        Paw _pawBackLeft;
        Paw _pawBackRight;
};
