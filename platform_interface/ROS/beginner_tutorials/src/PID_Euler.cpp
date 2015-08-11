#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"
#include "custom_messages/driveMessage.h"
#include "std_msgs/Float32.h"
#include "beginner_tutorials/driveCmd.h"

const float sampling_rate = 10; //sampling rate in hz
const float ub = 5; // upper and lower bounds on control signal 
const float lb = -5; // same for throttle and steering as of now

const float ff_vel = 0; //feed forward term for vel
const float ff_steer = 0; //ff term for steer

void SaturateSignal(float signal, const float lb, const float ub); // function to act as saturator


int main(int argc, char **argv)
{
	ros::init(argc,argv,"teleop_traxxas");
	ros::NodeHandle n;
	// listen to sensor message in order to compute e(k)
	//Declare the publisher
	ros::Publisher pub_teleop = n.advertise<beginner_tutorials::driveCmd>("teleop_commands",1000);

	//The variable that has to be published
	beginner_tutorials::driveCmd tele_cmd;

	//sampling rate for PID using Euler

	float h = 1/sampling_rate;

	// variables for PID for velocity and steering
	static float u_km1_vel = 0; // u(k-1)
	static float u_vel  = 0; // u(k) 
	static float e_km1_vel = 0; // e(k-1)
	static float e_km2_vel = 0; // e(k-2)
	static float e_k_vel = 0; // e(k)

	static float u_km1_steer = 0; // u(k-1)
	static float u_steer  = 0; // u(k) 
	static float e_km1_steer = 0; // e(k-1)
	static float e_km2_steer = 0; // e(k-2)
	static float e_k_steer = 0; // e(k)


	// PID gains
	const float Kp_vel = 0;
	const float Kd_vel = 0;
	const float Ki_vel = 0;

	const float Kp_steer = 0;
	const float Kd_steer = 0;
	const float Ki_steer = 0;


	while(ros::ok())
	{

		// PID for velocity

		// feed forward term if any for vel
		ff_vel = 0;

		//error signal for velocity
		//progress time first, information is old
		e_km2_vel = e_km1_vel;
		e_km1_vel = e_k_vel;
		e_k_vel = 0; //compute e_k

		u_km1_vel = u_k_vel;
		u_k_vel = u_km1_vel + (1/h)*(Kp_vel*h + Kd_vel + Ki_vel*h^2)*e_k_vel + (1/h)*(-Kp_vel*h-2*Kd_vel)*e_km1_vel + (1/h)*Kd_vel*e_km2_vel + ff_vel;


		// PID for steering

		// feed forward term if any for steer
		ff_steer = 0;

		//error signal for steering
		//progress time first, information is old
		e_km2_steer = e_km1_steer;
		e_km1_steer = e_k_steer;
		e_k_steer = 0; //compute e_k

		u_km1_steer = u_k_steer;
		u_k_steer = u_km1_steer + (1/h)*(Kp_steer*h + Kd_steer + Ki_steer*h^2)*e_k_steer + (1/h)*(-Kp_steer*h-2*Kd_steer)*e_km1_steer + (1/h)*Kd_steer*e_km2_steer + ff_steer;

		//check between -5 and +5 publish 

		SaturateSignal(u_k_steer,ub,lb); // saturator
		SaturateSignal(u_k_vel,ub,lb);

		ROS_INFO("Steering: %f; Throttle %f", tele_cmd.steering, tele_cmd.throttle);
		pub_teleop.publish(tele_cmd);



		// maintain rate
		ros::spinOnce();
		loop_rate.sleep();




	}
}


void SaturateSignal(float signal, const float lb, const float ub)
{
	if(signal<=ub && signal>=lb) 
		signal=signal;
	else if(signal>ub) 
		signal = ub;
	else if(signal<lb) 
		signal = lb;

}
