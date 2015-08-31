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

echo "Unloading usbtmc driver..."
modprobe --quiet --remove usbtmc

echo "Re-loading usbtmc driver..."
insmod ./usbtmc-linux3.10.40-grinch-21.3.4.ko 

lsmod | grep usbtmc
if [ $? -eq 0 ]; then
    echo "Driver loaded."
else
    echo "Driver not loaded!"
fi

chmod 666 /dev/usbtmc0
