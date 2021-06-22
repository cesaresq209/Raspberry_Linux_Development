/*

Example of programming GPIO from C or C++ using the sysfs interface on
a Raspberry Pi.

Will toggle GPIO4 (physical pin 7)
*/

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) 
{
    printf("Hello World with GPIO, RonFace IMage!!\n");

    printf("GPIO Exported\n");
    // Export the desired pin by writing to /sys/class/gpio/export
    int fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/export");
        exit(1);
    }

    if (write(fd, "4", 2) != 2) {
        perror("Error writing to /sys/class/gpio/export");
        exit(1);
    }

    close(fd);

    // Set the pin to be an output by writing "out" to /sys/class/gpio/gpio4/direction
    printf("GPIO Cofigured\n");
    fd = open("/sys/class/gpio/gpio4/direction", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio4/direction");
        exit(1);
    }

    if (write(fd, "out", 3) != 3) {
        perror("Error writing to /sys/class/gpio/gpio4/direction");
        exit(1);
    }

    close(fd);

    fd = open("/sys/class/gpio/gpio4/value", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio4/value");
        exit(1);
    }

    // Toggle LED 2 s on, 2S off, 10 times
    printf("Loop Init:\n");
    for (int i = 0; i < 10; i++) 
    {

        printf("Pin ON!!\n");
        if (write(fd, "1", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio4/value");
            exit(1);
        }
        sleep(2);

        printf("Pin OFF!\n");
        if (write(fd, "0", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio4/value");
            exit(1);
        }
        sleep(2);
    }

    close(fd);

    // Unexport the pin by writing to /sys/class/gpio/unexport

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (fd == -1) {
        perror("Unable to open /sys/class/gpio/unexport");
        exit(1);
    }

    if (write(fd, "4", 2) != 2) {
        perror("Error writing to /sys/class/gpio/unexport");
        exit(1);
    }

    close(fd);

    // And exit
    return 0;
}
