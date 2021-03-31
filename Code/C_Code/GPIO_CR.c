#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <pigpio.h>

/*
 * Code developed using pigpio library. 
 * For more information visit: http://abyz.me.uk/rpi/pigpio/cif.html
 * to compile using this library: 
 * gcc -Wall -pthread -o program.bin program.c -lpigpio -lrt
*/


int main(int argc, char *argv[])
{
   if (gpioInitialise()<0)
   {
      printf("Initializing GPIO Library \n \r");
      return 1;
   } 
   printf("Initializing GPIO 25 \n");
   gpioSetMode(25,PI_OUTPUT);
   while (1)
   {
      printf("Turning LED ON\n");
      gpioWrite(25,1);
      sleep(5);
      printf("Turning LED OFF\n");
      gpioWrite(25,0);
      sleep(5);
   }
   printf("Program End\n");
   gpioTerminate();
   
}
