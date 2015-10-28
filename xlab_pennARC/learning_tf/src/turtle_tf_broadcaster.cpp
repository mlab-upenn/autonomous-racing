#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(10);

  tf::TransformBroadcaster broadcaster;
  ROS_INFO("sdjg");
  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0., 0.0, 0.0)),
        ros::Time::now(),"base_frame", "laser"));
	ROS_INFO("H");
    r.sleep();
  }
}
