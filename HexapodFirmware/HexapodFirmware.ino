#include "Body.hpp"
#include "Bluetooth.hpp"

Body *hexapodBody;
Bluetooth *bluetooth;

void setup()
{
    hexapodBody = new Body();    
    bluetooth = new Bluetooth();
    hexapodBody->reset();

    bluetooth->write("Initialization ...\n");
}

void loop()
{
    char c = bluetooth->read();

    switch (c)
    {
        case -1:
            hexapodBody->reset();
            return;
        case 'F':
            hexapodBody->moveForward();
            bluetooth->write("FORWARD\n");
            break;
        case 'B':
            hexapodBody->moveBackward();
            bluetooth->write("BACKWARD\n");
            break;
        case 'L':
            hexapodBody->turnLeft();
            bluetooth->write("LEFT\n");
            break;
        case 'R':
            hexapodBody->turnRight();
            bluetooth->write("RIGHT\n");
            break;
        case 'S':
            hexapodBody->reset();
            bluetooth->write("STOP\n");
            break;
        default:
            hexapodBody->reset();
            bluetooth->write("UNKNOWN CASE'" + String(c, DEC) + "', RESET\n");
            return;
    }
}
