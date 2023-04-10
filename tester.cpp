// Last edit 03/09/2023 by Valerie Duffey
#include "mbed.h"
#include <iostream>


AnalogIn LightSensor(PTB0);
AnalogIn TemperatureSensor(PTB1);
//InterruptIn Button(PTB3);

//AnalogIn TorqueSensor(PTC9);

DigitalOut GREEN_LED(LED2);

//DigitalOut Motor(PTC2);
DigitalOut LED_1(PTD5);
DigitalOut LED_2(PTA13);
DigitalOut ROW1(PTB8);
DigitalOut ROW2(PTB9);
DigitalOut ROW3(PTB10);
DigitalOut R1P1(PTB11);
DigitalOut R1P2(PTE2);
DigitalOut R1P3(PTE3);
DigitalOut R2P1(PTE4);
DigitalOut R2P2(PTE5);
DigitalOut R2P3(PTC9);
DigitalOut R3P1(PTC8);
DigitalOut R3P2(PTA5);
DigitalOut R3P3(PTA4);
DigitalOut TemperatureHotLED(PTE20);
DigitalOut TemperatureColdLED(PTE21);
DigitalOut PhotoHigh(PTE29);
DigitalOut PhotoDark(PTE30);

#define Vsupply 3.3f //microcontroller voltage supply 3.3V

//variables for light sensor
float LightSensorDigiValue; //the A/D converter value read by the controller input pin
float LightSensorVoltValue; //voltage on the controller input pin
float LdrResistance; //photoresistance value
#define LdrBiasResistor 10000.0f //Bias resistor (lower leg of voltage divider) for LDR

//variables for temperature sensor
float TemperatureSensorDigiValue; //the A/D converter value read by the controller input pin
float TemperatureSensorVoltValue; //the voltage on the controller input pin (across the 10k resistor) from the temperature sensor voltage divider
float ThermistorResistance; //computed from the voltage drop value across the thermistor
float ThermistorTemperature; //approximate ambient temperature measured by thermistor
#define ThermistorBiasResistor 10000.0f //Bias resistor (lower leg of voltage divider) for thermistor

//variables for torque sensor
float MotorCurrentDigiValue; //the A/D converter value ready by the controller input pin
float MotorCurrentVoltValue; //the voltage on the controller input pin (across the 10 ohm resistor) from the motor torque sensor
float MotorCurrent; //computed from the voltage value
#define MotorSeriesResistance 10.0f //resistance of torque (current) sensing resistor in series with the Motor

// Variables to hold control reference values.
//Need to make them based off of environment
float LightBrightResistanceLimit = 1900.0; // Bright level
float LightDarkResistanceLimit = 35000.0; //Dark level
float TemperatureHotLimit = 30.0; // Overheat level
float TemperatureColdLimit = 15.0; //Too cold level
float MotorCurrentLimit = 0.1; //enter a reference current in amperes for motor torque deactivation

void WorldRefresh(void){
    //cout << "On to the next world!" << endl;
    //refresh lights
    //cout << "button pressed.\n";
    ROW1 = 0;
    ROW2 = 0; 
    ROW3 = 0; 
    R1P1 = 0;
    R1P2 = 0;
    R1P3 = 0;
    R2P1 = 0;
    R2P2 = 0;
    R2P3 = 0;
    R3P1 = 0;
    R3P2 = 0;
    R3P3 = 0;
    GREEN_LED = 0;
  
}

float getPhotoResistance(void){    
    LightSensorDigiValue = LightSensor.read(); //read the LightSensor A/D value    
    LightSensorVoltValue = Vsupply*LightSensorDigiValue; //convert to voltage    
    LdrResistance = LdrBiasResistor*(
    (Vsupply - LightSensorVoltValue) / LightSensorVoltValue); //voltage divider equation to determine LDR resistance
    return LdrResistance;
}

float getThermistorTemperature(void){
    TemperatureSensorDigiValue = TemperatureSensor.read();    
    TemperatureSensorVoltValue = Vsupply*TemperatureSensorDigiValue;    
    ThermistorResistance = ThermistorBiasResistor*(
    (Vsupply - TemperatureSensorVoltValue) / TemperatureSensorVoltValue);
    ThermistorTemperature = (
    (ThermistorResistance - 10000.0)/(-320.0)
    ) + 25.0;
    return ThermistorTemperature;
}

void CheckTemperatureSensor(void){
    if(getThermistorTemperature() >= TemperatureHotLimit)
        {        
        cout << "temperature beyond limit!" << endl;
        TemperatureHotLED = 1;
        TemperatureColdLED = 0;
        }
    else if(getThermistorTemperature() <= TemperatureColdLimit)
        {        
        cout << "temperature below limit!" << endl;
        TemperatureColdLED = 1;
        TemperatureHotLED =0;
        }
    else{
        cout << "Does nothing \n" << endl;
        TemperatureHotLED = 0; //OFF
        TemperatureColdLED = 0; //OFF
        }
}

void CheckLightSensor(void){
    if(getPhotoResistance() < LightBrightResistanceLimit)
        {        
        cout << "Too Bright!" << endl;
        PhotoHigh = 1;
        PhotoDark = 0;
        }
    else if(getPhotoResistance() > LightDarkResistanceLimit)
        {        
        cout << "Too Dark!" << endl;
        PhotoDark = 1;
        PhotoHigh = 0;
        }
    else{
        cout << "Does nothing \n" << endl;
        PhotoHigh = 0; //OFF
        PhotoDark = 0; //OFF
        }
}

// float getMotorCurrent(void)
// {
//     MotorCurrentDigiValue = TorqueSensor.read();
//     MotorCurrentVoltValue = Vsupply*MotorCurrentDigiValue;
//     MotorCurrent = MotorCurrentVoltValue / MotorSeriesResistance;
//     return MotorCurrent;
// }
// // This function will check the Over Torque analog input.
// void CheckTorqueSensor(void)
// {
//     if (getMotorCurrent() >= MotorCurrentLimit)
//     {
//     cout << "motor current beyond limit" << endl;
//     Motor = 0;
//     }
// }

void CheckPeople(){
    ROW1 = 1;
    ROW2 = 1; 
    ROW3 = 1; 
    R1P1 = 1;
    R1P2 = 1;
    R1P3 = 1;
    R2P1 = 1;
    R2P2 = 1;
    R2P3 = 1;
    R3P1 = 1;
    R3P2 = 1;
    R3P3 = 1;
    }

// void isRunning(void){
//         // Blink the blue LED once to indicate the code is running.
//     GREEN_LED = 0;
//     // GREEN_LED = !GREEN_LED;
    
//     // wait_us(1000000);
    
//     // GREEN_LED = !GREEN_LED;
// }
// Standard entry point in C++.
int main(void)
{
    cout << "Welcome, please see the training box for further instructions. \n";
    // Attach the functions to the hardware interrupt pins.
    
    //Button.rise(&WorldRefresh);
    GREEN_LED = 1;
    
    // Blink the blue LED once to indicate the code is running.
    
    GREEN_LED = !GREEN_LED;
    
    wait_us(1000000);
    
    GREEN_LED = !GREEN_LED;
    // Initialize LED outputs to OFF (LED logic is inverted)
    
    while(true) {
        // Check the analog inputs
        //Motor = 1;

        //isRunning();
        // CheckTemperatureSensor();
        // CheckLightSensor();
        CheckPeople();
        

        // cout << "\n\rLDR Resistance: " << getPhotoResistance() << endl;
        
        // cout << "\rCurrent Temperature Value: " << getThermistorTemperature() << endl;
        
        
        // wait_us(1000000); // Wait 1 second before repeating the loop.

        
    }
    //cout << "You have completed your training. You are welcomed to Godhood."<< std::endl;
}
