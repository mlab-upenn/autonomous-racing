#ifndef _ROS_statistics_msgs_Stats1D_h
#define _ROS_statistics_msgs_Stats1D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace statistics_msgs
{

  class Stats1D : public ros::Msg
  {
    public:
      double min;
      double max;
      double mean;
      double variance;
      int64_t N;

    Stats1D():
      min(0),
      max(0),
      mean(0),
      variance(0),
      N(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_min;
      u_min.real = this->min;
      *(outbuffer + offset + 0) = (u_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_min.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_min.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_min.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_min.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->min);
      union {
        double real;
        uint64_t base;
      } u_max;
      u_max.real = this->max;
      *(outbuffer + offset + 0) = (u_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max);
      union {
        double real;
        uint64_t base;
      } u_mean;
      u_mean.real = this->mean;
      *(outbuffer + offset + 0) = (u_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mean.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mean.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mean.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mean.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mean.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mean);
      union {
        double real;
        uint64_t base;
      } u_variance;
      u_variance.real = this->variance;
      *(outbuffer + offset + 0) = (u_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->variance);
      union {
        int64_t real;
        uint64_t base;
      } u_N;
      u_N.real = this->N;
      *(outbuffer + offset + 0) = (u_N.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_N.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_N.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_N.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_N.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_N.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_N.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_N.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->N);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_min;
      u_min.base = 0;
      u_min.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_min.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_min.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_min.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_min.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->min = u_min.real;
      offset += sizeof(this->min);
      union {
        double real;
        uint64_t base;
      } u_max;
      u_max.base = 0;
      u_max.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max = u_max.real;
      offset += sizeof(this->max);
      union {
        double real;
        uint64_t base;
      } u_mean;
      u_mean.base = 0;
      u_mean.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mean.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mean.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mean.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mean.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mean.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mean.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mean.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mean = u_mean.real;
      offset += sizeof(this->mean);
      union {
        double real;
        uint64_t base;
      } u_variance;
      u_variance.base = 0;
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->variance = u_variance.real;
      offset += sizeof(this->variance);
      union {
        int64_t real;
        uint64_t base;
      } u_N;
      u_N.base = 0;
      u_N.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_N.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_N.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_N.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_N.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_N.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_N.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_N.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->N = u_N.real;
      offset += sizeof(this->N);
     return offset;
    }

    const char * getType(){ return "statistics_msgs/Stats1D"; };
    const char * getMD5(){ return "5e29efbcd70d63a82b5ddfac24a5bc4b"; };

  };

}
#endif