#ifndef _ROS_asctec_hl_comm_mav_ctrl_h
#define _ROS_asctec_hl_comm_mav_ctrl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace asctec_hl_comm
{

  class mav_ctrl : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int8_t type;
      float x;
      float y;
      float z;
      float yaw;
      float v_max_xy;
      float v_max_z;
      enum { acceleration =  1 };
      enum { velocity =  2 };
      enum { position =  3 };
      enum { velocity_body =  4 };
      enum { position_body =  5 };

    mav_ctrl():
      header(),
      type(0),
      x(0),
      y(0),
      z(0),
      yaw(0),
      v_max_xy(0),
      v_max_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_v_max_xy;
      u_v_max_xy.real = this->v_max_xy;
      *(outbuffer + offset + 0) = (u_v_max_xy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_max_xy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_max_xy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_max_xy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_max_xy);
      union {
        float real;
        uint32_t base;
      } u_v_max_z;
      u_v_max_z.real = this->v_max_z;
      *(outbuffer + offset + 0) = (u_v_max_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_max_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_max_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_max_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_max_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        float real;
        uint32_t base;
      } u_v_max_xy;
      u_v_max_xy.base = 0;
      u_v_max_xy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_max_xy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_max_xy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_max_xy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_max_xy = u_v_max_xy.real;
      offset += sizeof(this->v_max_xy);
      union {
        float real;
        uint32_t base;
      } u_v_max_z;
      u_v_max_z.base = 0;
      u_v_max_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_max_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_max_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_max_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_max_z = u_v_max_z.real;
      offset += sizeof(this->v_max_z);
     return offset;
    }

    const char * getType(){ return "asctec_hl_comm/mav_ctrl"; };
    const char * getMD5(){ return "845e0a830a06ad942cc0b1907c31bc38"; };

  };

}
#endif