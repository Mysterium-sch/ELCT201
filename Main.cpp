// Last edit 03/09/2023 by Valerie Duffey
#include "mbed.h"
#include <iostream>
#include "platform/mbed_thread.h"
#include "death.h"
#include <string>
#include "tsi_sensor.h"

//NEED CORRECT PIN NUMBERS
AnalogIn LightSensor(PTE20);
AnalogIn TemperatureSensor(PTE21);
AnalogIn TorqueSensor(PTC1);
InterruptIn WorldRefresh(PTD1);

DigitalOut OutputMotor(PTC9);

DigitalOut LED_1(PTC7);
DigitalOut LED_2(PTC0);
DigitalOut LED_3(PTC3);
DigitalOut LED_4(PTE29);
DigitalOut LED_5(PTE30);
DigitalOut LED_6(PTB0);
DigitalOut LED_7(PTB2);
DigitalOut LED_8(PTB3);
DigitalOut LED_9(PTC2); 

DigitalOut LED_N(PTC4);
DigitalOut LED_M(PTB1);
DigitalOut LED_A(PTE3);

DigitalOut TemperatureHotLED(PTB8);
DigitalOut TemperatureColdLED(PTB9);
DigitalOut PhotoHigh(PTE5);
DigitalOut PhotoDark(PTE4);

InterruptIn Wind(PTD3);
InterruptIn Greed(PTD2);
InterruptIn Religion(PTD0);
InterruptIn Plague(PTD5);
InterruptIn Love(PTA13);
InterruptIn Aliens(PTA5);
InterruptIn Gun(PTA12);

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
Death *NOMAD = new Death("NOMAD");
Death *MODERN = new Death("MODERN");
Death *ADVANCED = new Death("ADVANCED");

//Global Variables
float roomTemp;
float roomLight;
bool ender[6] = {false,false,false,false,false, false};
bool gameOver = false;
bool restart = false;
string outcome;
string curPlace = "none";

// This function will be attached to the World Refresh button interrupt.
void WorldRefresher(void)
{
    restart = true;
}

void eventhandler(std::string event) {
    if(event.compare("no")!=0) {
    if(curPlace.compare("ADVANCED") == 0) {
        ADVANCED->eventHandler(event);
    } else if(curPlace.compare("MODERN") == 0) {
        MODERN->eventHandler(event);
    } else if (curPlace.compare("NOMAD") == 0) {
        NOMAD->eventHandler(event);
    }
    outcome = "no";
    }
}

void Winder(void) {
	outcome = "wind";
}

void Greeder(void) {
	outcome = "greed";
}
void Religioner(void) {
	outcome = "religion";
}
void Plaguer(void) {
	outcome = "plague";
}
void Lover(void) {
	outcome = "love";
}
void Aliener(void) {
	outcome = "alien";
}
void Gunner(void) {
	outcome = "gun";
}

float getMotorCurrent(void)
{

    MotorCurrentDigiValue = TorqueSensor.read(); //read the Torque A/D value
    MotorCurrentVoltValue = Vsupply*MotorCurrentDigiValue; //convert to voltage
    MotorCurrent = MotorCurrentVoltValue/MotorSeriesResistance; 

    return MotorCurrent;
}

// This function will check the Over Torque analog input.
bool CheckTorqueSensor(void)
{
     if(getMotorCurrent() >= MotorCurrentLimit) {
        return true;
    }
    return false;
 }
void Volcanoy(void)
{
       if((rand() % (100 + 1)) == 1) {
        OutputMotor = 1;
        cout << "A volcano is starting to emerge in " << curPlace << " if it is not stopped, everyone will die.\n";
        for(int i = 0; i<10; i++) {
            if(CheckTorqueSensor()) {
                i=11;
                OutputMotor = 0;
            } else {
                wait_us(1000000);
            }
        }
        if(OutputMotor==1) {
            eventhandler("volcano");
            OutputMotor=0;
        }
       wait_us(1000000);
    }
}

bool endingsTracker() {

    string endings[6] = {"christmas", "cultural","nothing", "warming", "gone", "beachday"};
    for(int i = 0; i<4;i++) {
        if(NOMAD->endHandler(endings[i])) {
            ender[i] = true;
            i = 10;
        }
        else if(MODERN->endHandler(endings[i])) {
            ender[i] = true;
            i = 10;
        }
        else if(ADVANCED->endHandler(endings[i])) {
            ender[i] = true;
            i = 10;
        }
        //gone
        else if(NOMAD->endHandler("gone") && MODERN->endHandler("gone") && ADVANCED->endHandler("gone")) {
            ender[4] = true;
            i = 10;
        }
        //gone
        else if(NOMAD->endHandler("beachday") && MODERN->endHandler("beachday") && ADVANCED->endHandler("beachday")) {
            ender[5] = true;
            i = 10;
        }
    }
    //check if all true
    bool done = true;
    for(int i = 0; i<6;i++) {
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

//This function will check the LDR analog input.
std::string CheckLightSensor(void)
{
	float light = getPhotoResistance();
    if(light < LightBrightResistanceLimit) {
        PhotoHigh = 1;
        PhotoDark = 0;
        return "light";
    }
    else if  (light > LightDarkResistanceLimit) {
        PhotoHigh = 0;
        PhotoDark = 1;
        return "dark";
    } else {
    PhotoHigh = 0;
    PhotoDark = 0;
    return "neither1";
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
	float temp = getThermistorTemperature();
    if( temp >= TemperatureHotLimit) {
        TemperatureColdLED = 0;
        TemperatureHotLED = 1;
         return "hot";
    }
    else if (temp <= TemperatureColdLimit) {
        TemperatureHotLED = 0;
        TemperatureColdLED = 1;
        return "cold";
    }
    return "neither2";
}

string CheckSensor(void) {
    std::string outcome = "no";
    string checklight = CheckLightSensor();
    if(checklight.compare("no") != 0) {
        outcome = checklight;
        return outcome;
    }
    string checktemp = CheckTemperatureSensor();
    if(checktemp.compare("no") != 0) {
        outcome = checktemp;
        return outcome;
    }
    return outcome;
}

void lightsUpdater(std::string place) {
    int people;
    if(place.compare("MODERN") == 0) {
            LED_N = 0;
            LED_M = 1;
            LED_A = 0;
            people = MODERN->getPeople();
            if(people == 3) {
                LED_4 = 1;
                LED_5 = 1;
                LED_6 = 1;
            }
            else if(people == 2) {
                LED_4 = 0;
                LED_5 = 1;
                LED_6 = 1;
            }
            else if(people == 1) {
                LED_4 = 0;
                LED_5 = 0;
                LED_6 = 1;
            }
            else if(people == 0) {
                LED_4 = 0;
                LED_5 = 0;
                LED_6 = 0;
            }
     }
    if(place.compare("NOMAD") == 0) {
            LED_M = 0;
            LED_N = 1;
            LED_A = 0;

            people = NOMAD->getPeople();
            if(people == 3) {
                LED_1 = 1;
                LED_2 = 1;
                LED_3 = 1;
            }
            else if(people == 2) {
                LED_1 = 0;
                LED_2 = 1;
                LED_3 = 1;
            }
            else if(people == 1) {
                LED_1 = 0;
                LED_2 = 0;
                LED_3 = 1;
            }
            else if(people == 0) {
                LED_1 = 0;
                LED_2 = 0;
                LED_3 = 0;
            }
    }
            
    if(place.compare("ADVANCED") == 0) {
            LED_M = 0;
            LED_N = 0;
            LED_A = 1;
            people = ADVANCED->getPeople();
            if(people == 3) {
                LED_7 = 1;
                LED_8 = 1;
                LED_9 = 1;
            }
            else if(people == 2) {
                LED_7 = 0;
                LED_8 = 1;
                LED_9 = 1;
            }
            else if(people == 1) {
                LED_7 = 0;
                LED_8 = 0;
                LED_9 = 1;
            }
            else if(people == 0) {
                LED_7 = 0;
                LED_8 = 0;
                LED_9 = 0;
            }
    }
}

void setRoomValues(void) {
	roomTemp = getThermistorTemperature();
	roomLight = getPhotoResistance();
		
	LightBrightResistanceLimit = roomLight - 5000;
	LightDarkResistanceLimit = roomLight + 5000;
	TemperatureHotLimit = roomTemp + 5;
	TemperatureColdLimit = roomTemp - 5;
}

// Standard entry point in C++.
int main(void)
{
    std::cout << "\n\rWelcome, please see the training box for further instructions.\n";
    // Attach the functions to the hardware interrupt pins.
    WorldRefresh.rise(&WorldRefresher);
// //Buttons
    Wind.rise(&Winder);
    Greed.rise(&Greeder);
    Religion.rise(&Religioner);
    Plague.rise(&Plaguer);
    Love.rise(&Lover);
    Aliens.rise(&Aliener);
    Gun.rise(&Gunner);

    LED_1 = 1;
    LED_2 = 1;
    LED_3 = 1;
    LED_4 = 1;
    LED_5 = 1;
    LED_6 = 1;
    LED_7 = 1;
    LED_8 = 1;
    LED_9 = 1;
//     // Initialize LED outputs to OFF (LED logic is inverted)
    setRoomValues();
    TSIAnalogSlider tsi(9, 10, 40);
    srand(time(0));
    while(!gameOver) {
        if(restart) {
            restart = false;
            cout << "\n\rOn to the next world!" << endl;
            delete NOMAD;
            delete MODERN;
            delete ADVANCED;
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
            LED_N = 0;
            LED_M = 0;
            LED_A = 0;
            //New Classes
            NOMAD = new Death("NOMAD");
            MODERN = new Death("MODERN");
            ADVANCED = new Death("ADVANCED");
        }
	    float holder = tsi.readPercentage();
        if(holder != 0 ) {
            if(holder <= 0.30) {  
                curPlace = "NOMAD";
                cout << "\n\rThis is the NOMADIC civilization.\n";
            } else if (holder >= 0.60){
                curPlace = "ADVANCED";
                cout << "\n\rThis is the ADVANCED civilization.\n";
            } else if ((holder >0.30) || (holder <0.60)) {
                curPlace = "MODERN";
                cout << "\n\rThis is the MODERN civilization.\n";
            }
        }       
        if (curPlace != "none") {
            Volcanoy();
        }
         // Check the analog inputs.
        eventhandler(outcome);
        eventhandler(CheckTemperatureSensor());
        eventhandler(CheckLightSensor());
        lightsUpdater(curPlace);
        gameOver = endingsTracker();
        wait_us(1000000); // Wait 1 second before repeating the loop.
    }
    std::cout << "\n\rYou have completed your training. You are welcomed to Godhood."<< std::endl;
}
// End of HardwareInterruptSeedCode
