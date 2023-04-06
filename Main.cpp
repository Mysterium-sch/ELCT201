// Last edit 03/09/2023 by Valerie Duffey
#include "mbed.h"
#include "Nomad.cpp"
#include "Modern.cpp"
#include "Advanced.cpp"
#include <iostream>

//NEED CORRECT PIN NUMBERS
AnalogIn LightSensor(PTB0);
AnalogIn TemperatureSensor(PTB1);
AnalogIn TorqueSensor(PTB2);
InterruptIn UniverseRestart(PTD4);
InterruptIn WorldRefresh(PTA12);
InterruptIn Volcano(PTA4);

DigitalOut LED_1();
DigitalOut LED_2();
DigitalOut LED_3();
DigitalOut LED_4();
DigitalOut LED_5();
DigitalOut LED_6();
DigitalOut LED_7();
DigitalOut LED_8();
DigitalOut LED_9();

DigitalOut LED_N();
DigitalOut LED_M();
DigitalOut LED_A();

DigitalIn Wind();
DigitalIn Humid();
DigitalIn Greed();
DigitalIn Religion();
DigitalIn GunPowder();
DigitalIn Plague();
DigitalIn Renaissance();
DigitalIn Love();
DigitalIn Aliens();

DigitalIn Nomad();
DigitalIn Modern();
DigitalIn Advanced();

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
float LightBrightResistanceLimit = 1600.0; // Bright level
float LightDarkResistanceLimit = 5000.0; //Dark level
float TemperatureHotLimit = 27.0; // Overheat level
float TemperatureColdLimit = 15.0; //Too cold level
float MotorCurrentLimit = 0.1; //enter a reference current in amperes for motor torque deactivation

// This function will be attached to the World Refresh button interrupt.
void WorldRefresh(void)
{
    //cout << "On to the next world" << endl;
    //refresh lights
    LED_1 = 1;
    LED_2 = 1;
    LED_3 = 1;
    LED_4 = 1;
    LED_5 = 1;
    LED_6 = 1;
    LED_7 = 1;
    LED_8 = 1;
    LED_9 = 1;
}

// This function will be attached to the Universe Refresh button interrupt.
void UniverseRestart(void)
{
    //cout << "Clean slate: you can now start the game over" << endl;
    //refresh lights
    LED_1 = 1;
    LED_2 = 1;
    LED_3 = 1;
    LED_4 = 1;
    LED_5 = 1;
    LED_6 = 1;
    LED_7 = 1;
    LED_8 = 1;
    LED_9 = 1;
    //take away booleans/memories
	
}
void Volcano(void)
{
	//std::string torque = CheckTorqueSensor();
	
}

//convert the input voltage from the light sensor to an LDR resistance value
//Resistance is inversely proportional to the amount of light

float getPhotoResistance(void)
{
    LightSensorDigiValue = LightSensor.read(); //read the LightSensor A/D value
    LightSensorVoltValue = Vsupply*LightSensorDigiValue; //convert to voltage
    LdrResistance = LdrBiasResistor*((Vsupply - LightSensorVoltValue) / LightSensorVoltValue); //voltage divider equation to determine LDR resistance

    return LdrResistance;
}

// This function will check the LDR analog input.
std::string CheckLightSensor(void)
{
    if(getPhotoResistance() <= LightBrightResistanceLimit) {
        return "bright";
    }
    else if  (getPhotoResistance() >= LightDarkResistanceLimit) {
        return "dark";
    }
    else {
        return "no";
    }
}

// This function converts the voltage value from the thermistor input to an approximate temperature
// in Celsius based on a linear approximation of the thermistor.
float getThermistorTemperature(void)
{
    TemperatureSensorDigiValue = TemperatureSensor.read(); //read the TemperatureSensor A/D value
    TemperatureSensorVoltValue = Vsupply*TemperatureSensorDigiValue; //convert to voltage
    ThermistorResistance = ThermistorBiasResistor*((Vsupply - TemperatureSensorVoltValue) / TemperatureSensorVoltValue); //voltage divider equation to determine LDR resistance
    ThermistorTemperature = ((ThermistorResistance - 10000.0)/(-320.0)) + 25.0; //temperature of the thermistor computed by a linear approximation of the device response

    return ThermistorTemperature;
}

//This function will check for a temperature triggered deactivation of the motor
std::string CheckTemperatureSensor(void)
{
    // STUDENT: EDIT HERE
    // Use the getThermistorTemperature() function defined above to obtain a temperature value to use for comparison and decision making with your TemperatureLimit
    if(getThermistorTemperature() >= TemperatureHotLimit) {
         return "hot";
    }
    else if (getThermistorTemperature() <= TemperatureColdLimit) {
        return "cold";
    }
    else {
        return "no";
    }
}

String CheckButton(void) {
    std::string outcome;
    if(CheckLightSensor().compare("no") != 0) {
        outcome = CheckLightSensor();
        return outcome;
    }
    if(CheckTemperatureSensor().compare("no") != 0) {
        outcome = CheckTemperatureSensor();
        return outcome;
    }
    /*if(CheckTorqueSensor().compare("no") != 0) {
        outcome = CheckTorqueSensor();
        return outcome;
    }*/
    if(Wind.read() == 0) {
        return "wind";
    }
    if(Humid.read() == 0) { 
        return "humid";
    }
    if(Greed.read() == 0) {
        return "greed"; 
    }
    if(Religion.read() == 0) { 
        return "religion"
    }
    if(GunPowder.read() == 0) { 
        return "gun";
    }
    if(Plague.read() == 0) { 
        return "plague";
    }
    if(Renaissance.read() == 0) { 
        return "renaissance";
    }
    if(Love.read() == 0) { 
        return "love";
    }
    if(Aliens.read() == 0) { 
        return "Aliens";
    }
    else {
        return "no";
    }
}
String CheckPlace(void) {
    if(Nomad.read() == 0) {
        return "Nomad";
    }
    if(Modern.read() == 0) { 
        return "Modern";
    }
    if(Advanced.read() == 0) {
        return "Advanced"; 
    }
    else {
        return "no";
    }
}
void Events(std::string place, std::string outcome) {
    int people;
    if(place.compare("Nomad") == 0) {
            LED_N = 0;
            LED_M = 1;
            LED_A = 1;
            if(outcome != "no") {
                Nomad.eventHandler(outcome);
                people = Nomad.getPeople();
                if(people == 0) {
                    LED_1 = 1;
                    LED_2 = 1;
                    LED_3 = 1;
                }
                if(people = 1) {
                    LED_1 = 0;
                    LED_2 = 1;
                    LED_3 = 1;
                }
                if(people = 2) {
                    LED_1 = 0;
                    LED_2 = 0;
                    LED_3 = 1;
                }
                if(people = 3) {
                    LED_1 = 0;
                    LED_2 = 0;
                    LED_3 = 0;
                }
            }
        }
        if(place.compare("Modern") == 0) {
            LED_M = 0;
            LED_N = 1;
            LED_A = 1;
            if(outcome != "no") {
                Modern.eventHandler(outcome);
                people = Modern.getPeople();
                if(people == 0) {
                    LED_4 = 1;
                    LED_5 = 1;
                    LED_6 = 1;
                }
                if(people = 1) {
                    LED_4 = 0;
                    LED_5 = 1;
                    LED_6 = 1;
                }
                if(people = 2) {
                    LED_4 = 0;
                    LED_5 = 0;
                    LED_6 = 1;
                }
                if(people = 3) {
                    LED_4 = 0;
                    LED_5 = 0;
                    LED_6 = 0;
                }
            }
        }
        if(place.compare("Advanced") == 0) {
            LED_A = 0;
            LED_M = 1;
            LED_N = 1;
            if(outcome != "no") {
                Advanced.eventHandler(outcome);
                people = Advanced.getPeople();
                if(people == 0) {
                    LED_7 = 1;
                    LED_8 = 1;
                    LED_9 = 1;
                }
                if(people = 1) {
                    LED_7 = 0;
                    LED_8 = 1;
                    LED_9 = 1;
                }
                if(people = 2) {
                    LED_7 = 0;
                    LED_8 = 0;
                    LED_9 = 1;
                }
                if(people = 3) {
                    LED_7 = 0;
                    LED_8 = 0;
                    LED_9 = 0;
                }
            }
        }
}

// Standard entry point in C++.
int main(void)
{
    // Attach the functions to the hardware interrupt pins.
    WorldRefresh.rise(&WorldRefresh);
    UniverseRestart.rise(&UniverseRestart);
    Volcano.rise(&Volcano);
    // Initialize LED outputs to OFF (LED logic is inverted)
    RED_LED = 1;
    GREEN_LED = 1;
    BLUE_LED = 1;
    
    while(true) {
        // Check the analog inputs.
        std::string outcome = CheckButton();
        std::string place = CheckPlace();
        Events(place, outcome);
        
        wait(1.0); // Wait 1 second before repeating the loop.
    }
}
// End of HardwareInterruptSeedCode
