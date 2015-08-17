#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"
#include "custom_messages/driveMessage.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int16.h"
#include "beginner_tutorials/driveCmd.h"
#include "math.h"




class PID_Event_Trig
{ 
	ros::NodeHandle n;
	ros::Publisher pub_teleop;
	ros::Subscriber vp_subscribe; //subscriber for vanishing point

	beginner_tutorials::driveCmd tele_cmd;

//	public:

	//Parameters for PID
	float sampling_rate; //sampling rate in hz, make it match the estimator/
	// error signal gen rate
	float ub; // upper and lower bounds on control signal 
	float lb; // same for throttle and steering as of now


	// PID gains
	float Kp_vel;
	float Kd_vel;
	float Ki_vel;

	float Kp_steer;
	float Kd_steer;
	float Ki_steer;
	//sampling rate for PID using Euler

	float h;



	// For vanishing point error signal
	float temp_steer_float;
	int temp_steer_int;

	// variables for PID for velocity and steering
	float u_km1_vel; // u(k-1)
	float u_k_vel; // u(k) 
	float e_km1_vel; // e(k-1)
	float e_km2_vel; // e(k-2)
	float e_k_vel; // e(k)


	float u_km1_steer; // u(k-1)
	float u_k_steer; // u(k) 
	float e_km1_steer; // e(k-1)
	float e_km2_steer; // e(k-2)
	float e_k_steer; // e(k)

	float ff_vel;  //feed forward term for vel
	float ff_steer; //ff term for steer

	float SaturateSignal(float signal, const float lb, const float ub); // function to act as saturator

	//	void vp_listen(const std_msgs::Int16::ConstPtr& msg); //everything happens on callback to this
	public:
	PID_Event_Trig(void)
	{
		// create publisher
		pub_teleop = n.advertise<beginner_tutorials::driveCmd>("teleop_commands",1000);
		// subscribe to vanishing point
		vp_subscribe = n.subscribe("vanishing_point_topic",1000,&PID_Event_Trig::vp_listen,this);

		// init PID params
		sampling_rate = 10; //in Hz
		h = 1/sampling_rate;
		ub = 5;
		lb = -5;
		temp_steer_float = 0;
		temp_steer_int = 0;	

		Kp_vel = 0;
		Kd_vel = 0;
		Ki_vel = 0;

		Kp_steer = 0.01;
		Kd_steer = 0;
		Ki_steer = 0;


		//init vars	
	 u_km1_vel = 0;
	 u_k_vel = 0;
	 e_km1_vel = 0;
	 e_km2_vel = 0;	
	 e_k_vel = 0;
	 ff_vel = 0;

	 u_km1_steer = 0;
	 u_k_steer = 0;
	 e_km1_steer = 0;
	 e_km2_steer = 0;	
	 e_k_steer = 0;
	 ff_steer = 0;

	}



	void vp_listen(const std_msgs::Int16::ConstPtr& msg)
	{
		ROS_INFO("I Heard vp");
		temp_steer_int = msg->data;
		temp_steer_float = 1.0*temp_steer_int; // this goes to e_k_steer

		PID_Event_Trig::PID_Event_steer();
		PID_Event_Trig::PID_Event_vel();
		PID_Event_Trig::PublishCommand();

	}



	/*	void PID_Event_steer();
		void PID_Event_vel();
		void PublishCommand();*/




	void PID_Event_vel()
	{
		// PID for velocity

		// feed forward term if any for vel
		ff_vel = 0.4;

		//error signal for velocity
		//progress time first, information is old
		e_km2_vel = e_km1_vel;
		e_km1_vel = e_k_vel;
		e_k_vel = 0; //compute e_k

		u_km1_vel = u_k_vel;
		u_k_vel = u_km1_vel + (1/h)*(Kp_vel*h + Kd_vel + Ki_vel*h*h)*e_k_vel + (1/h)*(-Kp_vel*h-2*Kd_vel)*e_km1_vel + (1/h)*Kd_vel*e_km2_vel;
	}

	void PID_Event_steer()
	{
		// PID for steering

		// feed forward term if any for steer
		ff_steer = 0;

		//error signal for steering
		//progress time first, information is old
		e_km2_steer = e_km1_steer;
		e_km1_steer = e_k_steer;
		e_k_steer = temp_steer_float; //compute e_k

		u_km1_steer = u_k_steer;
		u_k_steer = u_km1_steer + (1/h)*(Kp_steer*h + Kd_steer + Ki_steer*h*h)*e_k_steer + (1/h)*(-Kp_steer*h-2*Kd_steer)*e_km1_steer + (1/h)*Kd_steer*e_km2_steer;
	}

	void PublishCommand()
	{
		//check between -5 and +5 publish 

		tele_cmd.steering = u_k_steer + ff_steer;
		tele_cmd.throttle = u_k_vel + ff_vel;

		tele_cmd.steering = SaturateSignal(tele_cmd.steering,ub,lb); // saturator
		tele_cmd.throttle = SaturateSignal(tele_cmd.throttle,ub,lb);

		ROS_INFO("Steering: %f; Throttle %f", tele_cmd.steering, tele_cmd.throttle);
		pub_teleop.publish(tele_cmd);



	}


};
float PID_Event_Trig::SaturateSignal(float signal, const float ub, const float lb)
{
	if(signal<=ub && signal>=lb) 
		signal=signal;
	else if(signal>ub) 
		signal = ub;
	else if(signal<lb) 
		signal = lb;
	return signal;

}



int main(int argc, char **argv)
{
	ros::init(argc,argv,"PID_Euler_EventTrig");
	PID_Event_Trig pid;
	ros::spin();
	return 0;
}



