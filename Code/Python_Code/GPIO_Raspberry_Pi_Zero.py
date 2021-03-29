#GPIO Zero Library used to handle GPIO
#For more information:https://gpiozero.readthedocs.io/en/stable/
from gpiozero import OutputDevice
from time import sleep

#Set GPIO 17 (Pin # 11) as an LED 
led = OutputDevice(17)
def main():
    while True:
        led.on()
        print("Led On")
        sleep(1)
        led.off()
        print("Led Off")
        sleep(1)
    
if __name__ == "__main__":
    main()
