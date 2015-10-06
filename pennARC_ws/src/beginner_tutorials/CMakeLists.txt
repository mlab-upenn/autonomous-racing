cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg custom_messages message_generation cv_bridge image_transport sensor_msgs)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ncurses++ REQUIRED ncurses++)

## Declare ROS messages and services
add_message_files(FILES Num.msg driveCmd.msg driveMessage.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs beginner_tutorials custom_messages)

## Declare a catkin package
catkin_package(
CATKIN_DEPENDS message_runtime
)

## Build all the packages
include_directories(include ${catkin_INCLUDE_DIRS} ${ncurses++_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker beginner_tutorials_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener beginner_tutorials_generate_messages_cpp)

add_executable(emergency_stop src/emergency_stop.cpp)
target_link_libraries(emergency_stop ${catkin_LIBRARIES})
add_dependencies(emergency_stop beginner_tutorials_generate_messages_cpp)

add_executable(driveControl src/driveControl.cpp)
target_link_libraries(driveControl ${catkin_LIBRARIES} ${ncurses++_LIBRARIES})
add_dependencies(driveControl beginner_tutorials_generate_messages_cpp)

add_executable(teleop_traxxas src/teleop_traxxas.cpp)
target_link_libraries(teleop_traxxas ${catkin_LIBRARIES} ncurses)
add_dependencies(teleop_traxxas beginner_tutorials_generate_messages_cpp)

add_executable(PID_Euler src/PID_Euler.cpp)
target_link_libraries(PID_Euler ${catkin_LIBRARIES})
add_dependencies(PID_Euler beginner_tutorials_generate_messages_cpp)

add_executable(PID_Euler_Event src/PID_Euler_EventTrig.cpp)
target_link_libraries(PID_Euler_Event ${catkin_LIBRARIES})
add_dependencies(PID_Euler_Event beginner_tutorials_generate_messages_cpp)

add_executable(vanishing_node src/vanishing_node.cpp)
target_link_libraries(vanishing_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)
add_dependencies(vanishing_node vanishing_generate_messages_cpp)

add_executable(approx_sync_node src/approx_syncTime.cpp)
target_link_libraries(approx_sync_node ${catkin_LIBRARIES})
add_dependencies(approx_sync_node beginner_tutorials_generate_messages_cpp)

#add_executable(mySync src/mySync.cpp)
#target_link_libraries(mySync ${catkin_LIBRARIES})
#add_dependencies(mySync beginner_tutorials_generate_messages_cpp)

add_executable(talkerim src/talkerim.cpp)
target_link_libraries(talkerim ${catkin_LIBRARIES})
add_dependencies(talkerim beginner_tutorials_generate_messages_cpp)

