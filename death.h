#ifndef _DEATH_
#define _DEATH_

#include "mbed.h"
#include <iostream>
#include <string>
#include "platform/mbed_thread.h"

using namespace std;

class Death {
    public:
    Death(string death);
    string getType();
    int getPeople();
    void eventHandler(std::string value);
    bool endHandler(std::string value);


    protected:
    int people;
    bool love, wind, greed, humid, gold, religion, gun, plague, renaissance, Aliens = false;
    bool cold, dark, hot, light = false;
    string world;
};

#endif