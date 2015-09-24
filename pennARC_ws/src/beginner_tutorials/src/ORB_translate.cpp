#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"
#include "custom_messages/driveMessage.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int16.h"
#include "beginner_tutorials/driveCmd.h"
#include "math.h"
#include <geometry_msgs/TransformStamped.h>
#include <visualization_msgs/Marker.h>
//#include "TransformStamped.h"

class ORB_translate
{ 
	ros::NodeHandle n;
	ros::Publisher ORB_6dof;
	ros::Subscriber ORB_MapSub; //subscriber for /ORB_SLAM/Map
	geometry_msgs::TransformStamped ORB_Pose;


	public:
	ORB_translate(void)
	{
		// create publisher
		ORB_6dof = n.advertise<geometry_msgs::TransformStamped>("ORB_Pose",1000);
		// subscribe to ORB_SLAM
		ORB_MapSub = n.subscribe("/ORB_SLAM/Map",1000,&ORB_translate::ORB_listen,this);
	}



	void ORB_listen(const visualization_msgs::Marker& ORB_Map)
	{
		ROS_INFO("I Heard ORB_SLAM");
		ORB_Pose.header.frame_id = "/ORB_SLAM/World";
		ORB_Pose.child_frame_id = "/ORB_SLAM/World";
		ORB_Pose.transform.translation.x = ORB_Map.pose.position.x;
		ORB_Pose.transform.translation.y = ORB_Map.pose.position.y;
		ORB_Pose.transform.translation.z = ORB_Map.pose.position.z;

		ORB_Pose.transform.rotation.x = ORB_Map.pose.orientation.x;
		ORB_Pose.transform.rotation.y = ORB_Map.pose.orientation.y;
		ORB_Pose.transform.rotation.z = ORB_Map.pose.orientation.z;
		ORB_Pose.transform.rotation.w = ORB_Map.pose.orientation.w;

		ORB_translate::PublishCommand();
	}


	void PublishCommand()
	{
		ROS_INFO("publishing ORB_Pose");
		ORB_6dof.publish(ORB_Pose);
	}


};


int main(int argc, char **argv)
{
	ros::init(argc,argv,"ORB_translate");
	ORB_translate thedawg;
	//	ROS_INFO("B_S");	
	ros::spin();
	//	ROS_INFO("A_S");
	return 0;
}



