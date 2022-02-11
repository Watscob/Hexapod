#include "Bluetooth.hpp"

Bluetooth::Bluetooth()
{
    Serial1.begin(9600);
}

char Bluetooth::read()
{
    char c = Serial1.read();

    while (Serial1.available())
    {
        c = Serial1.read();
    }

    return c;
}

void Bluetooth::write(String str)
{
    //char buf[str.length()];
    //str.toCharArray(buf, str.length());
//
    //Serial1.write(buf);
    Serial1.print(str);
}