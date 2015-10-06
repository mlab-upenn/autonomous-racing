#ifndef _ROS_asctec_hl_comm_mav_ekf_h
#define _ROS_asctec_hl_comm_mav_ekf_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace asctec_hl_comm
{

  class mav_ekf : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Vector3 angular_velocity;
      geometry_msgs::Vector3 linear_acceleration;
      uint8_t state_length;
      float st_state;
      float * state;
      int32_t flag;
      enum { ignore_state =  0 };
      enum { current_state =  1 };
      enum { initialization =  2 };
      enum { state_correction =  3 };

    mav_ekf():
      header(),
      angular_velocity(),
      linear_acceleration(),
      state_length(0), state(NULL),
      flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->angular_velocity.serialize(outbuffer + offset);
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      *(outbuffer + offset++) = state_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < state_length; i++){
      union {
        float real;
        uint32_t base;
      } u_statei;
      u_statei.real = this->state[i];
      *(outbuffer + offset + 0) = (u_statei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_statei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_statei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_statei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_flag;
      u_flag.real = this->flag;
      *(outbuffer + offset + 0) = (u_flag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_flag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_flag.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->angular_velocity.deserialize(inbuffer + offset);
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
      uint8_t state_lengthT = *(inbuffer + offset++);
      if(state_lengthT > state_length)
        this->state = (float*)realloc(this->state, state_lengthT * sizeof(float));
      offset += 3;
      state_length = state_lengthT;
      for( uint8_t i = 0; i < state_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_state;
      u_st_state.base = 0;
      u_st_state.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_state.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_state.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_state.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_state = u_st_state.real;
      offset += sizeof(this->st_state);
        memcpy( &(this->state[i]), &(this->st_state), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_flag;
      u_flag.base = 0;
      u_flag.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flag.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_flag.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_flag.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->flag = u_flag.real;
      offset += sizeof(this->flag);
     return offset;
    }

    const char * getType(){ return "asctec_hl_comm/mav_ekf"; };
    const char * getMD5(){ return "0710aec5a114bc946c3d7687c8e5a0bd"; };

  };

}
#endif