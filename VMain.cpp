// Last edit 10/19/2022
#include "mbed.h"
#include <iostream>
#include <cstdlib>

DigitalOut OUTPUT1(PTC2);
DigitalOut Output2(PTC1);

#define Vsupply 3.3f //microcontroller voltage supply 3.3V


//variables for torque sensor
float MotorCurrentDigiValue; //the A/D converter value ready by the controller input pin
float MotorCurrentVoltValue; //the voltage on the controller input pin (across the 10 ohm resistor) from the motor torque sensor
float MotorCurrent; //computed from the voltage value
#define MotorSeriesResistance 10.0f //resistance of torque (current) sensing resistor in series with the Motor

float MotorCurrentLimit = 0.3; //enter a reference current in amperes for motor torque deactivation


//This function will determine the motor current in amperes
float getMotorCurrent(void)
{

    MotorCurrentDigiValue = TorqueSensor.read(); //read the Torque A/D value
    MotorCurrentVoltValue = Vsupply*MotorCurrentDigiValue; //convert to voltage
    MotorCurrent = MotorCurrentVoltValue/MotorSeriesResistance; 
    
   

    return MotorCurrent;
}

// This function will check the Over Torque analog input.
void CheckTorqueSensor(void)
{

     if(getMotorCurrent() >= MotorCurrentLimit) {
        OUTPUT2 = 1;
        OUTPUT1 = 0;
    }


}

// Standard entry point in C++.
int main(void)
{
    
    while(true) {
       if((rand() % (1000 + 1)) == 0) {
        OUTPUT1 =1;
        OUTPUT2 = 0;
        for(int i = 0; i<10; i++) {
            CheckTorqueSensor();
            if(OUTPUT2 ==1) {
                i=11;
                OUTPUT2 = 0;
            } else {
                wait_us(1000000);
            }
        }
       }
    }
}
// End of HardwareInterruptSeedCode