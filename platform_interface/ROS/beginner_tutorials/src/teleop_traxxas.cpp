#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"
#include "custom_messages/driveMessage.h"
#include "std_msgs/Float32.h"
#include "beginner_tutorials/driveCmd.h"
#include <stdio.h> // these two are reqd for the nonBlocking nature
#include <ncurses.h> //system dependencies use the <> and external dependencies that the user provides have to be specified with ""

int main(int argc, char **argv)
{
	ros::init(argc,argv,"teleop_traxxas");
	ros::NodeHandle n;

	//Declare the publisher
	ros::Publisher pub_teleop = n.advertise<beginner_tutorials::driveCmd>("teleop_commands",1000);

	//The vaeaible that has to be published
	beginner_tutorials::driveCmd tele_cmd;

	//Declare the base values
	float turn = 0;
	float steer_default = 0;
	float heading = 0; // Both these values should correspond to the mid pt value - 9830
	float heading_default = 0;

	float old_throttle_state = 0;
	float current_throttle_state = 0.0;

	float old_steer_state = 0;
	float current_steer_state = 0;

	ros::Rate loop_rate(10);

	//the ncurses parameters
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);
	nodelay(stdscr,FALSE);
	timeout(0);
	
	int ch;

	//custom_messages::driveMessage driveIt; //The user defined message that we will be broadcasting

	while(ros::ok())
	{

		
		ch = wgetch(stdscr);

		switch(ch){

			case KEY_UP:
			//	printw("%d",ch);
				heading = +1;
				break;

			case KEY_DOWN:
			//	printw("%d",ch);
				heading = -1;
				break;

			case KEY_LEFT: //The +- of this will have to be configured
			//	printw("%d",ch);
				current_steer_state = old_steer_state + 0.1;
				if (current_steer_state > 5) //Limited at full turn - approx 60degrees
					current_steer_state = 5; 
				turn = +1;
//				ROS_INFO("L");
				break;

			case KEY_RIGHT:
			//	printw("%d",ch);
				current_steer_state = old_steer_state - 0.1;
				if (current_steer_state < -5) //Limited at full turn - approx 60degrees
					current_steer_state = -5;
				turn = -1;
				break;

			case 119:
			//	printw("w");
				current_throttle_state = heading*(old_throttle_state + 0.1);
//				printw("%f",current_throttle_state);
				if (current_throttle_state > 1) //limits t 10mph?
					current_throttle_state = 1;
				break;

			case 115:
				current_throttle_state = heading*(old_throttle_state + 0.1);	
				if (current_throttle_state < -1)
					current_throttle_state = -1;
			//	printw("s");
				break;
	

  	     		default:
       				current_throttle_state = heading_default;
       				current_steer_state = steer_default;
//				ROS_INFO("Def");
		          //  	printw("%d",ch);
	       			break;
        }
//	endwin();
        tele_cmd.throttle = current_throttle_state;
        tele_cmd.steering = current_steer_state;
	
	old_steer_state = current_steer_state;
	old_throttle_state = heading*current_throttle_state; 
        ROS_INFO("Steering: %f; Throttle %f", tele_cmd.steering, tele_cmd.throttle);
        pub_teleop.publish(tele_cmd);
	
//	endwin();
		

        ros::spinOnce();
        loop_rate.sleep();
    }
    endwin();
    return 0;
}

	
