# CMake generated Testfile for 
# Source directory: /home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/camera1394
# Build directory: /home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/build/camera1394
# 
# This file includes the relevent testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(_ctest_camera1394_rostest_tests_no_device_node.test "/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/hydro/share/catkin/cmake/test/run_tests.py" "/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/build/test_results/camera1394/rostest-tests_no_device_node.xml" "--return-code" "/opt/ros/hydro/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/camera1394 --package=camera1394 --results-filename tests_no_device_node.xml /home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/camera1394/tests/no_device_node.test ")
ADD_TEST(_ctest_camera1394_rostest_tests_no_device_nodelet.test "/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/build/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/hydro/share/catkin/cmake/test/run_tests.py" "/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/build/test_results/camera1394/rostest-tests_no_device_nodelet.xml" "--return-code" "/opt/ros/hydro/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/camera1394 --package=camera1394 --results-filename tests_no_device_nodelet.xml /home/dhruva/Documents/mlab/autonomous-racing/pennARC_ws/src/camera1394/tests/no_device_nodelet.test ")
SUBDIRS(src/nodes)
