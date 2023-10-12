#include "mbed.h"

// main() runs in its own thread in the OS

DigitalOut red(PC_2,1);
DigitalOut yel(PC_3,1);
DigitalOut grn(PC_6,1);
#define WAIT_TIME_MS 2000

int main()
{
    wait_us(2000000); 
    while (true) {
red = 1;
wait_us(2000000);
red = 0;
wait_us(2000000);
red = 1;
yel = 1;
wait_us(2000000);
red = 0;
yel = 0;
wait_us(2000000);
grn = 1;
wait_us(2000000);
grn = 0;
wait_us(2000000);
yel = 1;
wait_us(2000000);
yel = 0;
wait_us(2000000);
yel = 1;
wait_us(2000000);
yel = 0;
wait_us(2000000);
yel = 1;
wait_us(2000000);
yel = 0;
wait_us(2000000);
yel = 1;
wait_us(2000000);
yel = 0;
wait_us(2000000);
    }
}

