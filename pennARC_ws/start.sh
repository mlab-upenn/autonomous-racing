# start roscore
screen -dmS roscore 
screen -S roscore -X stuff 'roscore^M'

# start reading frames into the camera
screen -dmS camera
screen -S camera -X stuff 'rosrun camera1394 camera1394_node _guid:=00b09d0100e62a67 _video_mode:=640x480_mono8 _iso_speed:=400 _frame_rate:=10^M'


echo "printing in main?"