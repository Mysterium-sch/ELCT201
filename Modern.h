#ifndef _MODERN_
#define _MODERN_

#include "mbed.h"


class Modern {
    public:
    Modern();
    int getPeople();
    void eventHandler(std::string value);
    bool endHandler(std::string value);


    protected:
    int people;
    bool love, wind, greed, humid, gold, religion, gun, plague, renaissance, love, Aliens = false;
    bool cold, dark, hot, light = false;
};

#endif