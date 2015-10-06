#ifndef _ROS_asctec_hl_comm_PositionWithCovarianceStamped_h
#define _ROS_asctec_hl_comm_PositionWithCovarianceStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace asctec_hl_comm
{

  class PositionWithCovarianceStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Point position;
      double covariance[9];

    PositionWithCovarianceStamped():
      header(),
      position(),
      covariance()
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
      } u_covariancei;
      u_covariancei.real = this->covariance[i];
      *(outbuffer + offset + 0) = (u_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_covariancei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_covariancei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_covariancei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_covariancei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_covariancei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->covariance[i]);
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
      } u_covariancei;
      u_covariancei.base = 0;
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->covariance[i] = u_covariancei.real;
      offset += sizeof(this->covariance[i]);
      }
     return offset;
    }

    const char * getType(){ return "asctec_hl_comm/PositionWithCovarianceStamped"; };
    const char * getMD5(){ return "3128d09129e2da15dcfe14f5a9b5a902"; };

  };

}
#endif