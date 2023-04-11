#ifndef _ADVANCED_
#define _ADVANCED_

#include "mbed.h"
#include <iostream>
#include <string>
#include "platform/mbed_thread.h"

using namespace std;


class Advanced {
    public:
    Advanced();
    int getPeople();
    void eventHandler(string value);
    bool endHandler(string value);


    protected:
    int people = 3;
    bool love, wind, greed, humid, gold, religion, gun, plague, renaissance, Aliens = false;
    bool cold, dark, hot, light = false;
};

#endif
