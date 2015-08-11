cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg custom_messages message_generation)
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
include_directories(include ${catkin_INCLUDE_DIRS} ${ncurses++_INCLUDE_DIRS})

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
target_link_libraries(PID_Euler ${catkin_LIBRARIES} ncurses)
add_dependencies(PID_Euler beginner_tutorials_generate_messages_cpp)

