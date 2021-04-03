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
   int handle;
   if (gpioInitialise()<0)
   {
      printf("Initializing GPIO Library Failed\n \r");
      return 1;
   } 
   handle = i2cOpen(1, 0x3F, 0);
   printf("Sending Data \n");
   i2cWriteByte(handle, 0xAA);
   printf("Program End\n");
   gpioTerminate();
   
}
