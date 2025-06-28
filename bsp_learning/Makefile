KCFLAGS += -Wno-error

KERNEL_DIR = /home/ningd/imx6ull/Linux-4.9.88

obj-m += chrdev.o

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
