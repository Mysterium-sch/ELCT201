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
    int love, wind, greed, religion, gun, plague, Aliens = 0;
    int cold, dark, hot, light, ending = 0;
    string world;
};

#endif
