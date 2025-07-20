KERNEL_DIR = /home/ningd/imx6ull/Linux-4.9.88

# A single .ko driver depending on multiple source files(a.c, b.c)
obj-m += chrdev.o
chrdev-y := a.o b.o

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
