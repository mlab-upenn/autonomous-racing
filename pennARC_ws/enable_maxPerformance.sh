#!/bin/bash

# max out the CPU
echo "userspace" > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
echo 2320500 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed
echo 2320500 > /sys/devices/system/cpu/cpu1/cpufreq/scaling_setspeed
echo 2320500 > /sys/devices/system/cpu/cpu2/cpufreq/scaling_setspeed
echo 2320500 > /sys/devices/system/cpu/cpu3/cpufreq/scaling_setspeed


# max out the GPU
echo 852000000 > /sys/kernel/debug/clock/override.gbus/rate
echo 1 > /sys/kernel/debug/clock/override.gbus/state

# verify the settings
echo "Active cores are:"
cat /sys/devices/system/cpu/online

echo "Frequency of CPU operation(Hz)"
cat /sys/devices/system/cpu/cpu3/cpufreq/scaling_cur_freq

echo "Frequency of operation of GPU(Hz)"
cat /sys/kernel/debug/clock/gbus/rate
