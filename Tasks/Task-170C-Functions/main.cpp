/*#include "uop_msb.h"
#include <chrono>
#include <cstdint>
#include <cstdio>
// LED Bar Display
BusOut dataBits(LED_D0_PIN, LED_D1_PIN, LED_D2_PIN, LED_D3_PIN, LED_D4_PIN, LED_D5_PIN, LED_D6_PIN, LED_D7_PIN);
DigitalOut LED_BAR_OE(LED_BAR_OE_PIN,1);
DigitalOut LED_RED_LE(LED_RED_LE_PIN);
DigitalOut LED_GRN_LE(LED_GRN_LE_PIN);
DigitalOut LED_BLUE_LE(LED_BLUE_LE_PIN);
AnalogIn pot(AN_POT_PIN);

void setLatch(uint8_t dat, char col);
void led_init(uint8_t dat, bool enabled);
int getDelayMS();

int getDelayMS() 
{
    float p = pot; // 0 ... 1
    int delay = 100 + 900*p;    //100...1000ms
    return delay;
}



void led_init(uint8_t dat, bool enabled)
{
    //Disable the LED outputs
    LED_BAR_OE = 1;

    //Set data to 0
    dataBits = dat;

    //Give a little time
    wait_us(1);

    //Enable all latches
    LED_RED_LE  = 1;
    LED_GRN_LE  = 1;
    LED_BLUE_LE  = 1;

    //Give a little time
    wait_us(1);

    //Enable all latches
    LED_RED_LE  = 0;
    LED_GRN_LE  = 0;
    LED_BLUE_LE  = 0;

    if (enabled) {
        LED_BAR_OE = 0;
    }
}






void setLatch(uint8_t dat, char col)
{
    //For safety
    LED_RED_LE = 0;
    //LED_GRN_LE = 0;
    //LED_BLUE_LE = 0;

    //Now follow the sequence
    wait_us(1);
    dataBits = dat;    //Set the 8-bit data pattern
    wait_us(1);




    //Depending on the chosen colour
    switch (col)
    {


        case 'r':
            LED_RED_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1);  
//for (unsigned int m=0; m<10; m++) {
    //unsigned short redarray[10];
    //redarray[m] = m+6;
    // LED_RED_LE =   redarray[m];
    // setLatch(redarray[m],'r');
    wait_us(10000);          // 10ms
    LED_RED_LE  = 0; 
//}
             //Ignore inputs (dataBits)
            break;



        case 'g':
            LED_GRN_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1);     
           // for (unsigned int o=0 ; o<10 ; o++) {
             //    unsigned short greenarray[10];
        //greenarray[o] = o+5;
       // setLatch(greenarray[o], 'g');
          wait_us(10000); 
         //    }    
            LED_GRN_LE  = 0;    //Ignore inputs (dataBits)
            break;




        case 'b':
            LED_BLUE_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1); 
          //  for (unsigned int p=0; p<10; p++) {
          //      unsigned short bluearray[10];
   // bluearray[p] = 6*p-1;
  //  setLatch(bluearray[p], 'b');
    wait_us(10000);          // 10ms
//}  


            LED_BLUE_LE  = 0;    //Ignore inputs (dataBits)

           
            break;
    }
    wait_us(1); 
}

int main()
{
      
    printf("Functions demo\n");

    led_init(0x00, true);

    //Update the red
    for (int m = 0 ; m<10 ; m++){

int n=0;
n=24*m+1;
int o=0;
o=2*(m-1)*(m-1);
int p=0;
p=3*m*m - 5;

unsigned short redarray[10] = {255, 165, 100, 55, 76, 10, 128, 200, 162, 2};
//edarray[m] = n;
//unsigned short greenarray[10];
//greenarray[m] = o;
//unsigned short bluearray[10];
//bluearray[m] = p;

    setLatch(redarray[m],'r');

    //Update the green
    //setLatch(greenarray[m], 'o');

    //Update the blue
    //setLatch(bluearray[m], 'p');

    

    while(true) {
        //Get delay value
        int delay_ms = getDelayMS();

        //Enable all the LED BAR Latch Outputs
        LED_BAR_OE = 0;

        //Wait
        wait_us(delay_ms*1000);

        //Disable the latch outputs
    
        LED_BAR_OE = 1;

        //Wait
        wait_us(delay_ms*1000);            
    }


    }
}*/

#include "uop_msb.h"
#include <cstdlib>
#include <chrono>
#include <cstdint>
#include <cstdio>

// LED Bar Display
BusOut dataBits(LED_D0_PIN, LED_D1_PIN, LED_D2_PIN, LED_D3_PIN, LED_D4_PIN, LED_D5_PIN, LED_D6_PIN, LED_D7_PIN);
DigitalOut LED_BAR_OE(LED_BAR_OE_PIN,1);
DigitalOut LED_RED_LE(LED_RED_LE_PIN);
DigitalOut LED_GRN_LE(LED_GRN_LE_PIN);
DigitalOut LED_BLUE_LE(LED_BLUE_LE_PIN);
AnalogIn pot(AN_POT_PIN);

void setLatch(uint8_t dat, char col);
void led_init(uint8_t dat, bool enabled);
int getDelayMS();
unsigned short redarray[10] = {255, 165, 100, 55, 76, 10, 128, 200, 162, 2};
unsigned short greenarray[10] = {111, 246, 3, 46, 199, 254 , 0, 123, 200, 70};
unsigned short bluearray[10] = {0 , 1 , 2 , 4, 8 , 16 , 32 , 64 , 128 , 255};

int main()
{
    printf("Functions demo\n");

    led_init(0x00, true);

    for(int m =0; m < 11; m++ ){
      if(m==10){
          m=0;
      }
      else{
        int red = redarray[m];
        int green = greenarray[m];
        int blue = bluearray[m];
        //Update the red
        setLatch(red,'r');
        //Update the green
        setLatch(green, 'g');
        //Update the blue
        setLatch(blue, 'b');
    
        //while(true) {
        //Get delay value
        int delay_ms = getDelayMS();

        //Enable all the LED BAR Latch Outputs
        LED_BAR_OE = 0;

        //Wait
        wait_us(delay_ms*1000);

        //Disable the latch outputs
        LED_BAR_OE = 1;
        
 printf("Functions demo\n");
        //Wait
        wait_us(delay_ms*1000);            
    //}
    }
    }
}

void setLatch(uint8_t dat, char col)
{
    //For safety
    LED_RED_LE = 0;
    LED_GRN_LE = 0;
    LED_BLUE_LE = 0;

    //Now follow the sequence
    wait_us(1);
    dataBits = dat;    //Set the 8-bit data pattern
    wait_us(1);

    //Depending on the chosen colour
    switch (col)
    {
        case 'r':
            LED_RED_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1);         
            LED_RED_LE  = 0;    //Ignore inputs (dataBits)
            break;
        case 'g':
            LED_GRN_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1);         
            LED_GRN_LE  = 0;    //Ignore inputs (dataBits)
            break;
        case 'b':
            LED_BLUE_LE  = 1;    //Copy dataBits to red latch outputs
            wait_us(1);         
            LED_BLUE_LE  = 0;    //Ignore inputs (dataBits)
            break;
    }
    wait_us(1); 
}

void led_init(uint8_t dat, bool enabled)
{
    //Disable the LED outputs
    LED_BAR_OE = 1;
    //Set data to 0
    dataBits = dat;

    //Give a little time
    wait_us(1);

    //Enable all latches
    LED_RED_LE  = 1;
    LED_GRN_LE  = 1;
    LED_BLUE_LE  = 1;

    //Give a little time
    wait_us(1);

    //Enable all latches
    LED_RED_LE  = 0;
    LED_GRN_LE  = 0;
    LED_BLUE_LE  = 0;

    if (enabled) {
        LED_BAR_OE = 0;
    }
}

int getDelayMS() 
{
    float p = pot; // 0 ... 1
    int delay = 100 + 900*p;    //100...1000ms
    return delay;
}


