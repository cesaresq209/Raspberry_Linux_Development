# Produce file Manual_Creation.o
obj-m += Manual_Creation.o

#Point to kernel directory build system
KDIR = /lib/modules/$(shell uname -r)/build

#Sub make system, build a set of modules
all:
	make -C $(KDIR)  M=$(shell pwd) modules

#Cleans 
clean:
	make -C $(KDIR)  M=$(shell pwd) clean
