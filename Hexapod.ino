#include "Body.hpp"

Body *hexapodBody;

int rep = 20;

void setup()
{
    hexapodBody = new Body();
}

void loop()
{
    if (rep <= 0)
    {
        hexapodBody->reset();
    }
    else
    {
        hexapodBody->moveForward();
        rep--;
    }
}
