# Connect to host with serial port
Please be noted the board is using **CP2104** over CH340 as the USB to UART bridge controller. Thus we have to install **CP210x** driver on Windows
## Download link
https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads.

## Steps to install
1. Download the driver and unzip it.
2. Right click on the silabser.inf file and select Install.

You'll see `Silicon Labs CP210x USB to UART Bridge(COMx) in the device manager.
Connect to the serial port with Mobaxterm.

**Note** 
Use the micro-usb cable with the ability to transfer data! Some cables are charge-only.

