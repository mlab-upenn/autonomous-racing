#ifndef _ROS_beginner_tutorials_driveMessage_h
#define _ROS_beginner_tutorials_driveMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace beginner_tutorials
{

  class driveMessage : public ros::Msg
  {
    public:
      int16_t steering;
      int16_t throttle;

    driveMessage():
      steering(0),
      throttle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_steering;
      u_steering.real = this->steering;
      *(outbuffer + offset + 0) = (u_steering.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steering.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steering);
      union {
        int16_t real;
        uint16_t base;
      } u_throttle;
      u_throttle.real = this->throttle;
      *(outbuffer + offset + 0) = (u_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->throttle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_steering;
      u_steering.base = 0;
      u_steering.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steering.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->steering = u_steering.real;
      offset += sizeof(this->steering);
      union {
        int16_t real;
        uint16_t base;
      } u_throttle;
      u_throttle.base = 0;
      u_throttle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->throttle = u_throttle.real;
      offset += sizeof(this->throttle);
     return offset;
    }

    const char * getType(){ return "beginner_tutorials/driveMessage"; };
    const char * getMD5(){ return "c4dd5817de7802d91e66008f92eca79e"; };

  };

}
#endif