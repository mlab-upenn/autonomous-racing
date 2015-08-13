#cd into working directory

# download the sdk/libraries for the appropriate OS
#wget http://www.ptgrey.com/support/downloads/10526/

# unzip
#tar zxvf flycapture2-2.8.3.1-amd64-pkg.tgz 

# follow instructions in readme

# install all ros camera drivers (will install camera1394)
echo "Installing ros camera drivers(camera1394).."
sudo apt-get install ros-indigo-camera-drivers

# install relevant dependencies
sudo apt-get install libraw1394-11 libgtk2.0-0 libgtkmm-2.4-dev libglademm-2.4-dev libgtkglextmm-x11-1.2-dev libusb-1.0-0

# After installing raw1394 you may need to add the raw1394 module to be loaded on start.  
# To do this just add "raw1394" to the /etc/modules file.
sudo sh -c 'echo "raw1394" >> /etc/modules'

# set confgure udev rules
echo "Launching conf script";
sudo sh flycapture2-2.8.3.1-amd64/flycap2-conf

# pointgrey SDK should be installed. 
# to check if it works, install coriander and see if video can be streamed
# if yes, perfect! connect the camera and run the scripts!
echo "Installing coriander..."
sudo apt-get install coriander




