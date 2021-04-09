ifneq ($(KERNELRELEASE),)
mymodule-objs := My_driver.o
obj-m := My_driver.o
else
PWD := $(shell pwd)
KVER :=$(shell uname -r)
KDIR :=/lib/modules/$(KVER)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	rm -f *.cmd *.o *.mod *.ko
endif