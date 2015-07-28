#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h" //not sure how to check if the header file is present                         // or not
#include <sstream>
#include "beginner_tutorials/Num.h"
#include "custom_messages/driveMessage.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "driveControl");
	
	ros::NodeHandle n;

	ros::Publisher drive_publisher = n.advertise<std_msgs::Float32>("drive_cmd_channel",1000);

	std_msgs::Float32 currentDrive_cmd;

	currentDrive_cmd.data = -2.1; //This is manually set right now, will be mapped to a 16bit register(PWM)

	ros::Rate loop_rate(10); //10 times a second - publish @

	while(ros::ok())
	{

		ROS_INFO("Drive Command Sent: %f",currentDrive_cmd.data);
	//	std::cout<<currentDrive_cmd.data<<"\n";
		drive_publisher.publish(currentDrive_cmd);
		loop_rate.sleep();		


	}
}


