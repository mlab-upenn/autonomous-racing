#ifndef _ROS_asctec_hl_comm_MotorSpeed_h
#define _ROS_asctec_hl_comm_MotorSpeed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace asctec_hl_comm
{

  class MotorSpeed : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int16_t motor_speed[6];

    MotorSpeed():
      header(),
      motor_speed()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_motor_speedi;
      u_motor_speedi.real = this->motor_speed[i];
      *(outbuffer + offset + 0) = (u_motor_speedi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_speedi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_speed[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_motor_speedi;
      u_motor_speedi.base = 0;
      u_motor_speedi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_speedi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motor_speed[i] = u_motor_speedi.real;
      offset += sizeof(this->motor_speed[i]);
      }
     return offset;
    }

    const char * getType(){ return "asctec_hl_comm/MotorSpeed"; };
    const char * getMD5(){ return "3070a95b3ba41b42ea1ab4ed7544fc82"; };

  };

}
#endif