#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"
#include "custom_messages/driveMessage.h"
#include "std_msgs/Float32.h"
#include "beginner_tutorials/driveCmd.h"
#include <stdio.h> // these two are reqd for the nonBlocking nature
//#include <ncurses.h> //system dependencies use the <> and external dependencies that the user provides have to be specified with ""
#include <termios.h>

struct termios initial_settings, new_settings;


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
	float heading = 1; // Both these values should correspond to the mid pt value - 9830
	float heading_default = 0;

	float old_throttle_state = 0;
	float current_throttle_state = 0.0;

	float old_steer_state = 0;
	float current_steer_state = 0;

//	ros::Rate loop_rate(6);


	//termios parameters
	tcgetattr(0,&initial_settings);// (int fd, struct termios *termios_p)  gets parameters associated with the object refered to by fd and the stores them in the object referenced by termios_p. Similarly for the tcsetattr()
 
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON; //c_lflags  - local flags; similarly there are control(c_cflags) and i/o flags
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_lflag &= ~ISIG;
	new_settings.c_cc[VMIN] = 0;
	new_settings.c_cc[VTIME] = 1; //Timeout for nonCannonical read in deciseconds
 
    tcsetattr(0, TCSANOW, &new_settings);

	//the ncurses parameters
//	initscr();
//	cbreak();
//	noecho();
//	keypad(stdscr,TRUE);
//	nodelay(stdscr,FALSE);
//	timeout(0);
	
	int ch, key;

	//custom_messages::driveMessage driveIt; //The user defined message that we will be broadcasting

	while(ros::ok())
	{

//		ROS_INFO("waiting for character\n");		
		//ch = wgetch(stdscr);
		ch = getchar();
		if(ch == 27)
		{
			getchar(); //remove that middle part
			key = getchar();
			if(key == 65)
			{
				if (heading == -1)
					current_throttle_state = 0;
				heading = 1;
//				ROS_INFO("U");
			}
			else if(key == 66)
			{
				if (heading == 1)
					current_throttle_state = 0;
				heading = -1;
			
//				ROS_INFO("D");
			}
			else if(key == 67)
			{
				current_steer_state = old_steer_state + 0.1;
					if (current_steer_state > 4)
						current_steer_state = 4;
//				ROS_INFO("R");
			}
			else if(key == 68)
			{
				current_steer_state = old_steer_state - 0.1;
				if(current_steer_state < -4)
					current_steer_state = -4;
//				ROS_INFO("L");
			}
			else if(key == -1)
			{
				ROS_INFO("You pressed ESC");
				break;
			}	
		}
		else if (ch == 119)
		{
		        current_throttle_state = old_throttle_state + 0.01;
			if (current_throttle_state > 1)
				current_throttle_state = 1;
//			ROS_INFO("w");
		}
		else if (ch == 115)
		{
			current_throttle_state = old_throttle_state - 0.01;
			if (current_throttle_state < 0.1)
				current_throttle_state = 0;
//			ROS_INFO("s");
		}
		else
		{
	//		current_throttle_state = 0;
			current_steer_state = 0;
//			ROS_INFO("%d\n",key);
		}

//		loop_rate.sleep();
		tele_cmd.throttle = heading*(current_throttle_state);
		tele_cmd.steering = current_steer_state;

		old_throttle_state = current_throttle_state;
		old_steer_state = current_steer_state;
                ROS_INFO("Steering: %f; Throttle %f ", tele_cmd.steering, tele_cmd.throttle);
                pub_teleop.publish(tele_cmd);

		ros::spinOnce();

    }
    tcsetattr(0, TCSANOW, &initial_settings);
    return(0);


}












// 		switch(ch){

// 			case KEY_UP:
// 			//	printw("%d",ch);
// 				heading = +1;
// 				break;

// 			case KEY_DOWN:
// 			//	printw("%d",ch);
// 				heading = -1;
// 				break;

// 			case KEY_LEFT: //The +- of this will have to be configured
// 			//	printw("%d",ch);
// 				current_steer_state = old_steer_state + 0.1;
// 				if (current_steer_state > 5) //Limited at full turn - approx 60degrees
// 					current_steer_state = 5; 
// 				turn = +1;
// //				ROS_INFO("L");
// 				break;

// 			case KEY_RIGHT:
// 			//	printw("%d",ch);
// 				current_steer_state = old_steer_state - 0.1;
// 				if (current_steer_state < -5) //Limited at full turn - approx 60degrees
// 					current_steer_state = -5;
// 				turn = -1;
// 				break;

// 			case 119:
// 			//	printw("w");
// 				current_throttle_state = heading*(old_throttle_state + 0.1);
// //				printw("%f",current_throttle_state);
// 				if (current_throttle_state > 1) //limits t 10mph?
// 					current_throttle_state = 1;
// 				break;

// 			case 115:
// 				current_throttle_state = heading*(old_throttle_state + 0.1);	
// 				if (current_throttle_state < -1)
// 					current_throttle_state = -1;
// 			//	printw("s");
// 				break;
	

//   	     		default:
//        				current_throttle_state = heading_default;
//        				current_steer_state = steer_default;
// //				ROS_INFO("Def");
// 		          //  	printw("%d",ch);
// 	       			break;
//         }
// //	endwin();
//         tele_cmd.throttle = current_throttle_state;
//         tele_cmd.steering = current_steer_state;
	
// 	old_steer_state = current_steer_state;
// 	old_throttle_state = heading*current_throttle_state; 
//         ROS_INFO("Steering: %f; Throttle %f", tele_cmd.steering, tele_cmd.throttle);
//         pub_teleop.publish(tele_cmd);
	
// //	endwin();
		

//         ros::spinOnce();
//         loop_rate.sleep();
//     }
//     endwin();
//     return 0;
// }

	
