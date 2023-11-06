#include "mbed.h"
#include "string.h"
#include <cstring>

DigitalOut greenLED(LED1);
DigitalOut blueLED(LED2);
DigitalOut redLED(LED3);

int main()
{
    while (true) {
        char cmdString[] = "red,blue,wait,green,wait,red,blue,green,wait,blue,green,wait";
        const char delim[]=",";
        char *nextString;

        //Search for next instance of delim    
        nextString = strtok(cmdString, delim);

        while (nextString != NULL) 
        {
            if(strcmp(nextString, "red")==0)
            {redLED=1; 
            wait_us(1000000);}
            else if(strcmp(nextString, "green")==0)
            {greenLED=1;
            wait_us(1000000); }
            else if (strcmp(nextString, "blue")==0) 
            {blueLED=1; 
            wait_us(1000000); }
            else if (strcmp(nextString, "wait")==0) 
            {
               wait_us(1000000); 
            redLED=0;
            blueLED=0;
            greenLED=0;
            wait_us(1000000);}

wait_us(1000000);

            printf("Found %s\n", nextString);
            printf("cmdString is now %s\n", cmdString);

            // TODO: Check which string is next
            //       and switch on the correct LED (or pause)

            nextString = strtok(NULL, delim);
        }
    }

}

