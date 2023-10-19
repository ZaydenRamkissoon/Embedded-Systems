#include "uop_msb.h"
#include <chrono>
#include <cstdint>
#include <cstdio>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;

double total = 0 ;
int main()
{
    unsigned short samples[50];

    for (unsigned int m=0; m<50; m++) {
        printf(" %d is %X \n", m , samples[m]);
    }
    wait_us(500000);

    // Automatic headlamp 
    while (true) {
double mean = 0.02*(total);
        printf ("Mean of samples is %.1f\n", mean );
        for (unsigned int m=0; m<50; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            samples[m] = ldrVal;
             total = total + samples[m];
             
             enum {OFF=0, ON} state;
        
        switch (state) {
            case OFF:
                if (mean > 0x8000) {
                    state = ON;
                    redLED = 1;
                    wait_us(20000000);
                   
                }
                break;
            case ON:
                if (mean < 0x6900) {
                    state = OFF;
                    redLED = 0;
                }
                break;
                 
        };

        //Wait 0.25 seconds
        wait_us(500000);

    }
            wait_us(10000);         // 10ms
     
        }
        

        // TASK a. Calculate the average value in samples

        // TASK b. Display to 1dp

        // TASK c. Switch green LED on when dark;
        
    }  
   



