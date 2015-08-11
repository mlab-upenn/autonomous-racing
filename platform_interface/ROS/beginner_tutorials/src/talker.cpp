#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8.h" //not sure how to check if the header file is present 			  // or not
#include "std_msgs/Float32.h"
 #include <sstream>
#include "beginner_tutorials/Num.h"
#include "beginner_tutorials/driveCmd.h"

#include "custom_messages/driveMessage.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
int stable_throttle = 9830; // This value might not lead to a 0 velocity/swivel signal
int stable_steering = 9830;

int incremental_PWM = 7; // This increment in the 16bit register should give an increment of 0.1mph

float throttle_cmd = 0;
float steering_cmd = 0;

void mapDriveCmd_PWM(float, float);
beginner_tutorials::Num inputMessage;

custom_messages::driveMessage drive_it;

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */

void driveControl_listen(const beginner_tutorials::driveCmd& msg)
{	
	throttle_cmd = msg.throttle;
	steering_cmd = msg.steering;
//	ROS_INFO("I heard the drive controller: Throttle: %f; Steering: %f",throttle_cmd, steering_cmd);
	mapDriveCmd_PWM(throttle_cmd, steering_cmd);
        
//        std::cout<<drive_it.throttle<<"\n";

}



int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "talker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
  //ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
//  ros::Publisher chatter_pub = n.advertise<std_msgs::UInt8>("chatter", 1000);

  ros::Publisher chatter_pub = n.advertise<custom_messages::driveMessage>("chatter", 1000);
  ros::Subscriber drive_subscriber = n.subscribe("teleop_commands",1000,driveControl_listen);

//  custom_messages::driveMessage drive_it;
  
  drive_it.steering = steering_cmd;
  drive_it.throttle = throttle_cmd;
  beginner_tutorials::Num myMsg;
  
  myMsg.num = 25;

  ros::Rate loop_rate(10); // 10 times a second

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
//    std_msgs::String msg;
    std_msgs::UInt8 msg;

    std::stringstream ss;
//    ss << "hello world " << count;
//    msg.data = ss.str();
  // *msg.data = 28;
  
     msg.data = 28;

//    ROS_INFO("%s", msg.data.c_str());
    ROS_INFO("Steering: %d; Throttle %d", drive_it.steering, drive_it.throttle);

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    chatter_pub.publish(drive_it);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}



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

//	int scaled_cmd;
	scaled_cmd = (int)100*drive_cmd_s;
//	int base;
	
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
