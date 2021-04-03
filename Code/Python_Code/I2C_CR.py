#Using SMBUS2 Library. For more information:
#https://smbus2.readthedocs.io/en/latest/
import smbus2

def main():
    print("Initializing I2C Bus")
    bus = smbus2.SMBus(1)
    print("Writing Byte")
    bus.write_byte(0x3F,0xAA)

if __name__ == "__main__":
    main()

