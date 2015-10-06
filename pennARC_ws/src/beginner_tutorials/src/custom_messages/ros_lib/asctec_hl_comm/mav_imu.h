#ifndef _ROS_asctec_hl_comm_mav_imu_h
#define _ROS_asctec_hl_comm_mav_imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace asctec_hl_comm
{

  class mav_imu : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Quaternion orientation;
      geometry_msgs::Vector3 angular_velocity;
      geometry_msgs::Vector3 acceleration;
      double height;
      double differential_height;

    mav_imu():
      header(),
      orientation(),
      angular_velocity(),
      acceleration(),
      height(0),
      differential_height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->angular_velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->height);
      union {
        double real;
        uint64_t base;
      } u_differential_height;
      u_differential_height.real = this->differential_height;
      *(outbuffer + offset + 0) = (u_differential_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_differential_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_differential_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_differential_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_differential_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_differential_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_differential_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_differential_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->differential_height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->angular_velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        double real;
        uint64_t base;
      } u_differential_height;
      u_differential_height.base = 0;
      u_differential_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_differential_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_differential_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_differential_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_differential_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_differential_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_differential_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_differential_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->differential_height = u_differential_height.real;
      offset += sizeof(this->differential_height);
     return offset;
    }

    const char * getType(){ return "asctec_hl_comm/mav_imu"; };
    const char * getMD5(){ return "fc0b109c033a4f5dccf47e9654e6b6c3"; };

  };

}
#endif