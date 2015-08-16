#include <ros.h>
#include <std_msgs/Int8.h>
#include <beginner_tutorials/Num.h>
#include <custom_messages/driveMessage.h>
#include <std_msgs/UInt8.h>


/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
//void chatterCallback(const std_msgs::String::ConstPtr& msg)
//{
//  ROS_INFO("I heard: [%s]", msg->data.c_str());
//}


ros::NodeHandle n;

int ENABLE = 1 ; // this becomes LOW when the emergency messge is recieved
unsigned int TOGGLE_STATE = 1;
//Both these pins are of different timers. Must set the frequencies individually
int steeringPin = 6;       // steering pwm pin. 
int throttlePin = 5;       // throttle pwm pin

int debugPin = 2;

const int32_t pwm_frequency = 100; //frequency (in Hz)
const int pwm_res = 16; //res in bits

void emergency_listen(const std_msgs::UInt8& msg)
{
  //ROS_INFO("I heard: [%d]", msg.data);
  if(msg.data)  {
  	ENABLE = 0;
  }
  else	
        ENABLE = 1;

}

void chatterCallback_driveMessage(const custom_messages::driveMessage& msg)
{
 if(ENABLE){
  
  
    
    digitalWrite(debugPin,TOGGLE_STATE);
    if(TOGGLE_STATE)
	    TOGGLE_STATE = 0;
    else
	    TOGGLE_STATE = 1;
    //analogWiteFrequency(pin, Duty_cycle);
    analogWriteFrequency(steeringPin,msg.steering);
    analogWriteFrequency(throttlePin,msg.throttle);
//    delay(10);
//    digitalWrite(debugPin,LOW);
//  ROS_INFO("I heard: Steering = [%d]; & Throttle = [%d]", msg.steering, msg.throttle);
//  else
//  ROS_INFO("I heard an EMERGENCY STOP");
  
}
}


  ros::Subscriber<custom_messages::driveMessage> sub("chatter",&chatterCallback_driveMessage);
  ros::Subscriber <std_msgs::UInt8> emergency_sub("nine11", &emergency_listen);




//void chatterCallback(const std_msgs::Int8::ConstPtr& msg)
//{
//  ROS_INFO("I heard: [%d]", msg->data);
//}






//
//void chatterCallback_myMessage(const beginner_tutorials::Num::ConstPtr& msg)
//{
//  ROS_INFO("I heard: [%d]", msg->num);
//}




//int main(int argc, char **argv)
void setup()
{
  pinMode(debugPin,OUTPUT);
  digitalWrite(debugPin,HIGH);
  delay(1000);
  digitalWrite(debugPin,LOW);

  n.initNode();
  n.subscribe(sub);
  n.subscribe(emergency_sub);
  analogWriteResolution(pwm_res);
  analogWriteFrequency(throttlePin,pwm_frequency);
  analogWriteFrequency(steeringPin,pwm_frequency);

}
   void loop(){
      n.spinOnce();  
   }
  


