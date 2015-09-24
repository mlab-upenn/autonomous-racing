#!/bin/bash


echo "Starting roscore..."
screen -dmS roscore 
screen -S roscore -X stuff 'roscore^M'

# start reading frames into the camera
echo "Starting to read camera frames..."
screen -dmS camera
screen -S camera -X stuff 'rosrun camera1394 camera1394_node _guid:=00b09d0100e62a67 _video_mode:=640x480_mono8 _iso_speed:=400 _frame_rate:=60^M'

sleep 0.2

echo "Start teleop"
screen -dmS teleop
screen -S teleop -X stuff 'rosrun beginner_tutorials teleop_traxxas^M'

sleep 0.2
# start talker ros
echo "Starting talker ros node.."
screen -dmS talker
screen -S talker -X stuff 'rosrun beginner_tutorials talker^M'

sleep 0.4

# start serial communication for PWM ros
echo "Starting serial communication..."
screen -dmS serial
screen -S serial -X stuff 'rosrun rosserial_python serial_node.py /dev/ttyACM0^M'

