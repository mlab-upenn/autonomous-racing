#ifndef _ROS_asctec_hl_comm_GpsCustomCartesian_h
#define _ROS_asctec_hl_comm_GpsCustomCartesian_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace asctec_hl_comm
{

  class GpsCustomCartesian : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Point position;
      double position_covariance[9];
      double velocity_x;
      double velocity_y;
      double velocity_covariance[4];

    GpsCustomCartesian():
      header(),
      position(),
      position_covariance(),
      velocity_x(0),
      velocity_y(0),
      velocity_covariance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_position_covariancei;
      u_position_covariancei.real = this->position_covariance[i];
      *(outbuffer + offset + 0) = (u_position_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position_covariancei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_position_covariancei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_position_covariancei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_position_covariancei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_position_covariancei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position_covariance[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_velocity_x;
      u_velocity_x.real = this->velocity_x;
      *(outbuffer + offset + 0) = (u_velocity_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocity_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocity_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocity_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocity_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity_x);
      union {
        double real;
        uint64_t base;
      } u_velocity_y;
      u_velocity_y.real = this->velocity_y;
      *(outbuffer + offset + 0) = (u_velocity_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocity_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocity_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocity_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocity_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity_y);
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_velocity_covariancei;
      u_velocity_covariancei.real = this->velocity_covariance[i];
      *(outbuffer + offset + 0) = (u_velocity_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_covariancei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocity_covariancei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocity_covariancei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocity_covariancei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocity_covariancei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity_covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      union {
        double real;
        uint64_t base;
      } u_position_covariancei;
      u_position_covariancei.base = 0;
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->position_covariance[i] = u_position_covariancei.real;
      offset += sizeof(this->position_covariance[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_velocity_x;
      u_velocity_x.base = 0;
      u_velocity_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocity_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocity_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocity_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocity_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocity_x = u_velocity_x.real;
      offset += sizeof(this->velocity_x);
      union {
        double real;
        uint64_t base;
      } u_velocity_y;
      u_velocity_y.base = 0;
      u_velocity_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocity_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocity_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocity_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocity_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocity_y = u_velocity_y.real;
      offset += sizeof(this->velocity_y);
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_velocity_covariancei;
      u_velocity_covariancei.base = 0;
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocity_covariance[i] = u_velocity_covariancei.real;
      offset += sizeof(this->velocity_covariance[i]);
      }
     return offset;
    }

    const char * getType(){ return "asctec_hl_comm/GpsCustomCartesian"; };
    const char * getMD5(){ return "5d2c0118ba9eb587c756024a82d4d4a6"; };

  };

}
#endif