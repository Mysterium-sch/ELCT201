// Last edit 03/09/2023 by Valerie Duffey
#include "mbed.h"
#include <iostream>
#include "platform/mbed_thread.h"
#include "Nomad.h"
#include "Modern.h"
#include "Advanced.h"
#include <string>
#include "tsi_sensor.h"

//NEED CORRECT PIN NUMBERS
AnalogIn LightSensor(PTB0);
AnalogIn TemperatureSensor(PTB1);
AnalogIn TorqueSensor(PTB2);
InterruptIn UniverseRestart(PTD4);
InterruptIn WorldRefresh(PTA12);
InterruptIn Volcano(PTA4);

DigitalOut OutputMotor(PTC2);

DigitalOut LED_1(PTB11);
DigitalOut LED_2(PTE2);
DigitalOut LED_3(PTE3);
DigitalOut LED_4(PTE4);
DigitalOut LED_5(PTE5);
DigitalOut LED_6(PTC9);
DigitalOut LED_7(PTC8);
DigitalOut LED_8(PTA5);
DigitalOut LED_9(PTA4);

DigitalOut LED_N(PTB8);
DigitalOut LED_M(PTB9);
DigitalOut LED_A(PTB10);

DigitalOut TemperatureHotLED(PTE20);
DigitalOut TemperatureColdLED(PTE21);
DigitalOut PhotoHigh(PTE29);
DigitalOut PhotoDark(PTE30);

InterruptIn Wind(PTC9);
InterruptIn Humid(PTC8);
InterruptIn Greed(PTA5);
InterruptIn Religion(PTA4);
InterruptIn GunPowder(PTC11);
InterruptIn Plague(PTC10);
InterruptIn Renaissance(PTC6);
InterruptIn Love(PTC5);
InterruptIn Aliens(PTC4);

//InterruptIn NomadSelect(PTC3);
//InterruptIn ModernSelect(PTD1);
//InterruptIn AdvancedSelect(PTD3);

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
float LightBrightResistanceLimit = 1600.0; // Bright level
float LightDarkResistanceLimit = 5000.0; //Dark level
float TemperatureHotLimit = 27.0; // Overheat level
float TemperatureColdLimit = 15.0; //Too cold level
float MotorCurrentLimit = 0.1; //enter a reference current in amperes for motor torque deactivation

//Classes
Nomad *nomad = new Nomad();
Modern *modern = new Modern();
Advanced *advanced = new Advanced();

//Global Variables
float roomTemp;
float roomLight;
bool ender[10] = {false,false,false,false,false,false,false,false,false,false};
bool gameOver = false;

// This function will be attached to the World Refresh button interrupt.
void WorldRefresher(void)
{
    cout << "On to the next world!" << endl;
    delete nomad;
    delete modern;
    delete advanced;
    //refresh lights
    LED_1 = 0;
    LED_2 = 0;
    LED_3 = 0;
    LED_4 = 0;
    LED_5 = 0;
    LED_6 = 0;
    LED_7 = 0;
    LED_8 = 0;
    LED_9 = 0;
    LED_N = 1;
    LED_M = 1;
    LED_A = 1;
    //New Classes
    nomad = new Nomad();
    modern = new Modern();
    advanced = new Advanced();
}
string Winder(void) {
}
string Humider(void) {
}
string Greeder(void) {
}
string Religioner(void) {
}
string GunPowderer(void) {
}
string Plaguer(void) {
}
string Renaissancer(void) {
}
string Lover(void) {
}
string Aliener(void) {
}

// This function will be attached to the Universe Refresh button interrupt.
void UniverseRestarter(void)
{
    cout << "Clean slate: you can now start the training simulation over" << endl;
    delete nomad;
    delete modern;
    delete advanced;
    //refresh lights
    LED_1 = 0;
    LED_2 = 0;
    LED_3 = 0;
    LED_4 = 0;
    LED_5 = 0;
    LED_6 = 0;
    LED_7 = 0;
    LED_8 = 0;
    LED_9 = 0;
    LED_N = 1;
    LED_M = 1;
    LED_A = 1;
    //New Classes
    nomad = new Nomad();
    modern = new Modern();
    advanced = new Advanced();
    //Reset Endings
    for(int i = 0; i<10; i++) {
        ender[i] = false;
    }
    bool gameOver = false;
}
void Volcanoy(void)
{
	srand(time(0));
    while(true) {
       if((rand() % (1000 + 1)) == 0) {
        OutputMotor = 1;
        for(int i = 0; i<10; i++) {
            CheckTorqueSensor();
            if(OutputMotor == 1) {
                i=11;
                OutputMotor = 0;
            } else {
                wait_us(1000000);
            }
        }
       }
       wait_us(1000000);
    }
}

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
        OutputMotor = 1;
    }
}
bool endingsTracker() {

    string endings[10] = {"peace", "god", "christmas", "cultural","nothing", "greedy", "before", "warming", "gone"};
    for(int i = 0; i<9;i++) {
        if(nomad->endHandler(endings[i])) {
            ender[i] = true;
            i = 10;
        }
        else if(modern->endHandler(endings[i])) {
            ender[i] = true;
            i = 10;
        }
        else if(advanced->endHandler(endings[i])) {
            ender[i] = true;
            i = 10;
        }
        //gone
        else if(nomad->endHandler("gone") && modern->endHandler("gone") && advanced->endHandler("gone")) {
            ender[9] = true;
            i = 10;
        }
    }
    //check if all true
    bool done = true;
    for(int i = 0; i<10;i++) {
        if(!ender[i]) {
            return false;
        }
    }
    return true;

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

string CheckButton(void) {
    std::string outcome;
    if(CheckLightSensor().compare("no") != 0) {
        outcome = CheckLightSensor();
        return outcome;
    }
    if(CheckTemperatureSensor().compare("no") != 0) {
        outcome = CheckTemperatureSensor();
        return outcome;
    }
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

void Events(std::string place, std::string outcome) {
    int people;
    if(place.compare("Nomad") == 0) {
            LED_N = 0;
            LED_M = 1;
            LED_A = 1;
            if(outcome != "no") {
                nomad->eventHandler(outcome);
                people = nomad->getPeople();
                if(people == 0) {
                    LED_1 = 1;
                    LED_2 = 1;
                    LED_3 = 1;
                }
                if(people == 1) {
                    LED_1 = 0;
                    LED_2 = 1;
                    LED_3 = 1;
                }
                if(people == 2) {
                    LED_1 = 0;
                    LED_2 = 0;
                    LED_3 = 1;
                }
                if(people == 3) {
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
                modern->eventHandler(outcome);
                people = modern->getPeople();
                if(people == 0) {
                    LED_4 = 1;
                    LED_5 = 1;
                    LED_6 = 1;
                }
                if(people == 1) {
                    LED_4 = 0;
                    LED_5 = 1;
                    LED_6 = 1;
                }
                if(people == 2) {
                    LED_4 = 0;
                    LED_5 = 0;
                    LED_6 = 1;
                }
                if(people == 3) {
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
                advanced->eventHandler(outcome);
                people = advanced->getPeople();
                if(people == 0) {
                    LED_7 = 1;
                    LED_8 = 1;
                    LED_9 = 1;
                }
                if(people == 1) {
                    LED_7 = 0;
                    LED_8 = 1;
                    LED_9 = 1;
                }
                if(people == 2) {
                    LED_7 = 0;
                    LED_8 = 0;
                    LED_9 = 1;
                }
                if(people == 3) {
                    LED_7 = 0;
                    LED_8 = 0;
                    LED_9 = 0;
                }
            }
        }
}
void setRoomValues(void) {
	roomTemp = getThermistorTemperature();
	roomLight = getPhotoResistance();
		
	LightBrightResistanceLimit = roomLight - 1000;
	LightDarkResistanceLimit = roomLight+1000;
	TemperatureHotLimit = roomTemp+10;
	TemperatureColdLimit = roomTemp-10;
}

// Standard entry point in C++.
int main(void)
{
    std::cout << "Welcome, please see the training box for further instructions.\n";
    // Attach the functions to the hardware interrupt pins.
    WorldRefresh.rise(&WorldRefresher);
    UniverseRestart.rise(&UniverseRestarter);
    Volcano.rise(&Volcanoy);
//Buttons
    Wind.rise(&Winder);
    Humid.rise(&Humider);
    Greed.rise(&Greeder);
    Religion.rise(&Religioner);
    GunPowder.rise(&GunPowderer);
    Plague.rise(&Plaguer);
    Renaissance.rise(&Renaissancer);
    Love.rise(&Lover);
    Aliens.rise(&Aliener);
    // Initialize LED outputs to OFF (LED logic is inverted)
    setRoomValues();
    TSIAnalogSlider tsi(9, 10, 40);

    while(!gameOver) {
	    float holder = tsi.readPercentage();
        string place = "no";
        if(holder <= 0.30) {  
            place = "Nomad";
        } else if (holder >= 0.60){
            place = "Advanced";
        } else {
            place = "Modern";
        }
        // Check the analog inputs.
        std::string outcome = CheckButton();
        Events(place, outcome);
        gameOver = endingsTracker();
        wait(1.0); // Wait 1 second before repeating the loop.
    }
    std::cout << "You have completed your training. You are welcomed to Godhood."<< std::endl;
}
// End of HardwareInterruptSeedCode
