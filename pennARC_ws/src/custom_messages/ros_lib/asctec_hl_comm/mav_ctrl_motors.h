#ifndef _ROS_SERVICE_mav_ctrl_motors_h
#define _ROS_SERVICE_mav_ctrl_motors_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace asctec_hl_comm
{

static const char MAV_CTRL_MOTORS[] = "asctec_hl_comm/mav_ctrl_motors";

  class mav_ctrl_motorsRequest : public ros::Msg
  {
    public:
      bool startMotors;

    mav_ctrl_motorsRequest():
      startMotors(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_startMotors;
      u_startMotors.real = this->startMotors;
      *(outbuffer + offset + 0) = (u_startMotors.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->startMotors);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_startMotors;
      u_startMotors.base = 0;
      u_startMotors.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->startMotors = u_startMotors.real;
      offset += sizeof(this->startMotors);
     return offset;
    }

    const char * getType(){ return MAV_CTRL_MOTORS; };
    const char * getMD5(){ return "6076998c2a5ec9144368e0457caa79ef"; };

  };

  class mav_ctrl_motorsResponse : public ros::Msg
  {
    public:
      bool motorsRunning;

    mav_ctrl_motorsResponse():
      motorsRunning(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_motorsRunning;
      u_motorsRunning.real = this->motorsRunning;
      *(outbuffer + offset + 0) = (u_motorsRunning.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motorsRunning);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_motorsRunning;
      u_motorsRunning.base = 0;
      u_motorsRunning.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motorsRunning = u_motorsRunning.real;
      offset += sizeof(this->motorsRunning);
     return offset;
    }

    const char * getType(){ return MAV_CTRL_MOTORS; };
    const char * getMD5(){ return "246eeab4e06271d99512461f49c049e7"; };

  };

  class mav_ctrl_motors {
    public:
    typedef mav_ctrl_motorsRequest Request;
    typedef mav_ctrl_motorsResponse Response;
  };

}
#endif
