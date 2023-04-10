#ifndef _ADVANCED_
#define _ADVANCED_

#include "mbed.h"


class Advacned {
    public:
    Advacned();
    int getPeople();
    void eventHandler(std::string value);
    bool endHandler(std::string value);


    protected:
    int people;
    bool love, wind, greed, humid, gold, religion, gun, plague, renaissance, love, Aliens = false;
    bool cold, dark, hot, light = false;
};

#endif