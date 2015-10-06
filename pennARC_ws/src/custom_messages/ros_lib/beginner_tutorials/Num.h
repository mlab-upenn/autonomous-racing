#ifndef _ROS_beginner_tutorials_Num_h
#define _ROS_beginner_tutorials_Num_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace beginner_tutorials
{

  class Num : public ros::Msg
  {
    public:
      int8_t num;

    Num():
      num(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_num;
      u_num.real = this->num;
      *(outbuffer + offset + 0) = (u_num.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->num);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_num;
      u_num.base = 0;
      u_num.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->num = u_num.real;
      offset += sizeof(this->num);
     return offset;
    }

    const char * getType(){ return "beginner_tutorials/Num"; };
    const char * getMD5(){ return "cf992509827662516557e7b1f30e20ce"; };

  };

}
#endif