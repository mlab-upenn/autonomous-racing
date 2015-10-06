#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float32.h"
#include <sstream>
#include "beginner_tutorials/Num.h"
#include "beginner_tutorials/driveCmd.h"
#include "std_msgs/Int16.h"
#include "custom_messages/onlySteering.h"
#include "custom_messages/driveMessage.h"
#include "custom_messages/driveMessage2.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class talker
{
  float throttle_cmd;
  float steering_cmd;

  custom_messages::driveMessage drive_it;
  custom_messages::onlySteering onlySt;

  const static int stable_throttle = 9830;
  const static int stable_steering = 9830;

  const static int incremental_PWM = 7; 
  
  ros::NodeHandle nh_;
  ros::Subscriber sub_;
  ros::Publisher chatter_pub_;

  std_msgs::Int16 new_steering;
  
  void mapDriveCmd_PWM(float drive_cmd_t, float drive_cmd_s)
  {
        int heading = 0;
        int turn; //Left is negative
        int scaled_cmd;
        scaled_cmd = (int)100*drive_cmd_t;
        int base;

        //decides the direction
        if (drive_cmd_t < 0)
                heading = -1;
        else
                heading = 1;

        base = std::abs(int(drive_cmd_t));


        drive_it.throttle = stable_throttle +heading*base*655; //The 0.01% change in speed;
//        std::cout<<drive_it.throttle<<"\n";   
        // the precision part
        int rem = std::abs(scaled_cmd) % 100;
        if (heading < 0)
                drive_it.throttle = drive_it.throttle - incremental_PWM*rem;
        else
                drive_it.throttle = drive_it.throttle + incremental_PWM*rem;

//      int scaled_cmd;
        scaled_cmd = (int)100*drive_cmd_s;
//      int base;

        if (drive_cmd_s < 0)
                turn = -1;
        else
                turn = 1;

        base = std::abs(int(drive_cmd_s));
        drive_it.steering = stable_steering +turn* base*655;
//        std::cout<<drive_it.throttle<<"\n";   
        // the precision part
         rem = std::abs(scaled_cmd) % 100;
        if (turn < 0)
                drive_it.steering = drive_it.steering - incremental_PWM*rem;
        else
                drive_it.steering = drive_it.steering + incremental_PWM*rem;


  }



  public:
	
	talker()
	{
//		chatter_pub_ = nh_.advertise<custom_messages::driveMessage2>("chatter",1000);
	//	chatter_pub_ = nh_.advertise<custom_messages::onlySteering>("chatter",1000);
		chatter_pub_ = nh_.advertise<custom_messages::driveMessage>("chatter",1000);
 	        sub_ = nh_.subscribe("teleop_commands",1000,&talker::callBack_driveControl, this); 	

	}	
	
	void callBack_driveControl(const beginner_tutorials::driveCmd& msg)
	{
		throttle_cmd = msg.throttle;
		steering_cmd = msg.steering;
        	talker::mapDriveCmd_PWM(throttle_cmd, steering_cmd);
		ROS_INFO("Throttle:%d,  Steering:%d",drive_it.throttle,drive_it.steering);
// 		onlySt.steering = drive_it.steering;
//		chatter_pub_.publish(short(drive_it.steering));
//		chatter_pub_.publish(onlySt);
		chatter_pub_.publish(drive_it);

	}
	
};

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talkerim");
  ros::NodeHandle n;

  talker talkObject;

  ros::spin();

  return 0;   

}
