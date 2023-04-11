#ifndef _MODERN_
#define _MODERN_

#include "mbed.h"
#include <iostream>
#include <string>
#include "platform/mbed_thread.h"


class Modern {
    public:
    Modern();
    int getPeople();
    void eventHandler(string value);
    bool endHandler(string value);


    protected:
    int people;
    bool love, wind, greed, humid, gold, religion, gun, plague, renaissance, Aliens = false;
    bool cold, dark, hot, light = false;
};

#endif
