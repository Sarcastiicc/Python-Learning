# Embedded Linux Driver Development

## Environment
Drivers compiling depends on the Linux kernel running on the target board.
Step to build the drivers (cross compiling)

1. Get the source code of the target kernel version under Ubuntu.
2. Get the config file of Linux kernel from target board.
    Copy the *config* file from `/proc/config.gz` of target board. Rename it with *.config* and move it to the root path of kernel source code.
3. Run `make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules` as we don't have to fully build the whole kernel.
4. Add environment variable `ARCH=arm` and `CROSS_COMPILE=arm-linux-gnueabihf-`.
5. run `make` under path of driver source.

Remember, the obj-m name(.o) in Makefile has to be aligned with the source .c file. Otherwise compiling failed.

## Potential issues could be encountered
During step3, we may get 
> /usr/bin/ld: scripts/dtc/dtc-parser.tab.o:(.bss+0x50): multiple definition of `yylloc'; scripts/dtc/dtc-lexer.lex.o:(.bss+0x0): first defined here.

This is because our Ubuntu version is a little bit new. To resolve it, we have to 
modify `<kernel_path>/scripts/dtc/dtc-lexer.lex.c_shipped` and search for `YYLTYPE yyloc`, prepend it with keyword `extern`.
