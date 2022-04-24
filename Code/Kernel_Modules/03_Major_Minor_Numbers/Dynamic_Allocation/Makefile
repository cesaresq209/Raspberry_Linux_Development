# Produce file Dynamic_Allocation.o
obj-m +=Dynamic_Allocation.o

#Point to kernel directory build system
KDIR = /lib/modules/$(shell uname -r)/build

#Sub make system, build a set of modules
all:
	make -C $(KDIR)  M=$(shell pwd) modules

#Cleans 
clean:
	make -C $(KDIR)  M=$(shell pwd) clean
