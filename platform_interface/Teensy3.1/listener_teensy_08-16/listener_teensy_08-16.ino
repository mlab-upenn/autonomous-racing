#include <ros.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>
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
int zero_steer = 9830;
int zero_throttle = 9865;


//Both these pins are of different timers. Must set the frequencies individually
int steeringPin = 6;       // steering pwm pin.
int throttlePin = 5;       // throttle pwm pin

int debugPin = 2;
int em_stop_pin = 13;

const int32_t pwm_frequency = 100; //frequency (in Hz)
const int pwm_res = 16; //res in bits
int16_t msg1;

void emergency_listen(const std_msgs::UInt8& msg)
{
  //ROS_INFO("I heard: [%d]", msg.data);
  if (msg.data)  {
    ENABLE = 0;
    digitalWrite(em_stop_pin, HIGH);
  }
  else
  {
    ENABLE = 1;
    digitalWrite(em_stop_pin, 0);
  }

}


 /*
void chatterCallback_driveMessage(const std_msgs::Int16& msg)
{
  if (ENABLE) {     
    //digitalWrite(em_stop_pin,HIGH);
    digitalWrite(em_stop_pin, HIGH);
    //analogWiteFrequency(pin, Duty_cycle);
    analogWrite(steeringPin, msg.data);
    delay(10);
    digitalWrite(em_stop_pin, LOW);
  }
  else
  {
    analogWrite(steeringPin, zero_steer);
    analogWrite(throttlePin, zero_throttle);
    digitalWrite(em_stop_pin, HIGH);
  }


}*/


void chatterCallback_driveMessage(const custom_messages::driveMessage& msg)
{
  if (ENABLE) {


    //digitalWrite(em_stop_pin,HIGH);
    digitalWrite(em_stop_pin, HIGH);
    //analogWiteFrequency(pin, Duty_cycle);
    analogWrite(steeringPin, msg.steering);
    analogWrite(throttlePin, msg.throttle);
    //delay(10);
    //digitalWrite(em_stop_pin, LOW);
    //  digitalWrite(em_stop_pin,LOW);
    //  ROS_INFO("I heard: Steering = [%d]; & Throttle = [%d]", msg.steering, msg.throttle);
    //  else
    //  ROS_INFO("I heard an EMERGENCY STOP");

  }
  else
  {
    analogWrite(steeringPin, zero_steer);
    analogWrite(throttlePin, zero_throttle);
    digitalWrite(em_stop_pin, HIGH);
  }
}



ros::Subscriber<custom_messages::driveMessage> sub("chatter", &chatterCallback_driveMessage);


//ros::Subscriber<std_msgs::Int16> sub("chatter", &chatterCallback_driveMessage);
ros::Subscriber <std_msgs::UInt8> emergency_sub("nine11", &emergency_listen);





//int main(int argc, char **argv)
void setup()
{
  pinMode(debugPin, OUTPUT);
  pinMode(em_stop_pin, OUTPUT);
  digitalWrite(em_stop_pin, HIGH);
  delay(1000);
  digitalWrite(em_stop_pin, LOW);

  n.initNode();
  n.subscribe(sub);
  n.subscribe(emergency_sub);
  //n.getHardware()->setBaud(256000);
  analogWriteResolution(pwm_res);
  analogWriteFrequency(throttlePin, pwm_frequency);
  analogWriteFrequency(steeringPin, pwm_frequency);

}
void loop() {
  n.spinOnce();
}



