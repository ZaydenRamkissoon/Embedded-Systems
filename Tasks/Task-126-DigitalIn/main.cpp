#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalOut redLED(PC_2); //Red Traffic 1
DigitalIn ButtonB(PG_1);
DigitalOut yellowLED(PC_3);

// main() runs in its own thread in the OS
int main()
{
    int btnA;
    int btnB;
    // Turn OFF the red LED
    redLED = 0;
    yellowLED = 0;


    while (true) {
    
        // Wait for the button to be pressed
        do {
            (btnA = ButtonA , btnB = ButtonB ); //Read button A
        } while ( btnA == btnB == 0);


        //Toggle the red LED
        yellowLED = !yellowLED;

        //Wait for noise to settle
        wait_us(10000);

        // Wait for the button to be released
        do {
             (btnA = ButtonA , btnB = ButtonB ); //Read button A
        } while (btnA == btnB ==1);

        //Wait for noise to settle
        wait_us(10000);
    }
}

