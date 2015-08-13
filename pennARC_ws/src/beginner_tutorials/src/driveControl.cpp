#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h" //not sure how to check if the header file is present                         // or not
#include <sstream>
#include "beginner_tutorials/Num.h"
#include "beginner_tutorials/driveCmd.h"

#include "beginner_tutorials/Num.h"

#include "custom_messages/driveMessage.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "driveControl");
	
	ros::NodeHandle n;

	ros::Publisher drive_publisher = n.advertise<beginner_tutorials::driveCmd>("drive_cmd_channel",1000);

	beginner_tutorials::Num currentDrive_cmd;
        beginner_tutorials::driveCmd DRIVE_FEED;

//	currentDrive_cmd.x = 0; //This is manually set right now, will be mapped to a 16bit register(PWM)
//	currentDrive_cmd.y = 0; //This is manually set right now, will be mapped to a 16bit register(PWM)
      
        DRIVE_FEED.throttle = 0.5;
	DRIVE_FEED.steering = 0.8;

	ros::Rate loop_rate(10); //10 times a second - publish @

	while(ros::ok())
	{

		ROS_INFO("Drive Command Sent. iThrottle =: %f",DRIVE_FEED.throttle);
	//	std::cout<<currentDrive_cmd.data<<"\n";
		drive_publisher.publish(DRIVE_FEED);
		loop_rate.sleep();		


	}
}


