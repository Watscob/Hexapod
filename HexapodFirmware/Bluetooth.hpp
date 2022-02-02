#pragma once

#include <Arduino.h>
#include "ArxContainer.h"

class Bluetooth
{
    public:
        Bluetooth();
        char read();
        void write(String str);
};