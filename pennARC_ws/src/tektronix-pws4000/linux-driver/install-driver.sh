#!/bin/bash

# ensure that we're running as root
if [ $UID -ne 0 ]; then
    echo "This script needs to be run as root, aborting."
    exit 1
fi

# check kernel version
if [ `uname -r` != "3.10.40-grinch-21.3.4" ]; then
    echo "Incompatible kernel version, aborting."
    exit 1
fi

echo "Copying driver file"
cp usbtmc-linux3.10.40-grinch-21.3.4.ko /lib/modules/3.10.40-grinch-21.3.4/kernel/drivers/usb/class/usbtmc.ko

# update /etc/modules
echo "Updating /etc/modules..."
echo -e "\n# to talk to Tektronix power supply\nusbtmc" >> /etc/modules

echo "Driver installed"
