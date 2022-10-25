/*

Example of programming GPIO from C or C++ using the Libgpiod interface
a Raspberry Pi.

Will toggle GPIO4 (physical pin 7)
*/

#include <stdio.h>
#include <unistd.h>
#include <gpiod.h>

int main(int argc, char **argv) 
{
    printf("Hello World with LIBGPIO !\n");

    struct gpiod_chip *chip;
    struct gpiod_line *lineLED;

    printf("Opening chip and taking line \n");

    chip = gpiod_chip_open_by_name("gpiochip0");
    
    lineLED = gpiod_chip_get_line(chip, 17);

    gpiod_line_request_output(lineLED, "demo", 0);

    // Toggle LED 2 s on, 2S off, 10 times
    printf("Loop Init:\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("LED ON!!\n");
        gpiod_line_set_value(lineLED, 1 );
        sleep(2);

        printf("LED OFF!\n");
        gpiod_line_set_value(lineLED, 0 );
        sleep(2);
    }
    printf("Loop done, releasing line and closing chip\n");
    gpiod_line_release(lineLED);
    gpiod_chip_close(chip);

    // And exit
    return 0;
}
