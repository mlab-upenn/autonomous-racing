#ifndef _ROS_image_exposure_msgs_SequenceExposureStatistics_h
#define _ROS_image_exposure_msgs_SequenceExposureStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "image_exposure_msgs/ImageExposureStatistics.h"

namespace image_exposure_msgs
{

  class SequenceExposureStatistics : public ros::Msg
  {
    public:
      uint8_t exposures_length;
      image_exposure_msgs::ImageExposureStatistics st_exposures;
      image_exposure_msgs::ImageExposureStatistics * exposures;
      uint32_t underExposed;
      uint32_t overExposed;
      double meanIrradiance;
      double minMeasurableIrradiance;
      double maxMeasurableIrradiance;
      double minObservedIrradiance;
      double maxObservedIrradiance;

    SequenceExposureStatistics():
      exposures_length(0), exposures(NULL),
      underExposed(0),
      overExposed(0),
      meanIrradiance(0),
      minMeasurableIrradiance(0),
      maxMeasurableIrradiance(0),
      minObservedIrradiance(0),
      maxObservedIrradiance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = exposures_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < exposures_length; i++){
      offset += this->exposures[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->underExposed >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->underExposed >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->underExposed >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->underExposed >> (8 * 3)) & 0xFF;
      offset += sizeof(this->underExposed);
      *(outbuffer + offset + 0) = (this->overExposed >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->overExposed >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->overExposed >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->overExposed >> (8 * 3)) & 0xFF;
      offset += sizeof(this->overExposed);
      union {
        double real;
        uint64_t base;
      } u_meanIrradiance;
      u_meanIrradiance.real = this->meanIrradiance;
      *(outbuffer + offset + 0) = (u_meanIrradiance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_meanIrradiance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_meanIrradiance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_meanIrradiance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_meanIrradiance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_meanIrradiance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_meanIrradiance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_meanIrradiance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->meanIrradiance);
      union {
        double real;
        uint64_t base;
      } u_minMeasurableIrradiance;
      u_minMeasurableIrradiance.real = this->minMeasurableIrradiance;
      *(outbuffer + offset + 0) = (u_minMeasurableIrradiance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_minMeasurableIrradiance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_minMeasurableIrradiance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_minMeasurableIrradiance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_minMeasurableIrradiance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_minMeasurableIrradiance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_minMeasurableIrradiance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_minMeasurableIrradiance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->minMeasurableIrradiance);
      union {
        double real;
        uint64_t base;
      } u_maxMeasurableIrradiance;
      u_maxMeasurableIrradiance.real = this->maxMeasurableIrradiance;
      *(outbuffer + offset + 0) = (u_maxMeasurableIrradiance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maxMeasurableIrradiance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maxMeasurableIrradiance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maxMeasurableIrradiance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_maxMeasurableIrradiance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_maxMeasurableIrradiance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_maxMeasurableIrradiance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_maxMeasurableIrradiance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->maxMeasurableIrradiance);
      union {
        double real;
        uint64_t base;
      } u_minObservedIrradiance;
      u_minObservedIrradiance.real = this->minObservedIrradiance;
      *(outbuffer + offset + 0) = (u_minObservedIrradiance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_minObservedIrradiance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_minObservedIrradiance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_minObservedIrradiance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_minObservedIrradiance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_minObservedIrradiance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_minObservedIrradiance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_minObservedIrradiance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->minObservedIrradiance);
      union {
        double real;
        uint64_t base;
      } u_maxObservedIrradiance;
      u_maxObservedIrradiance.real = this->maxObservedIrradiance;
      *(outbuffer + offset + 0) = (u_maxObservedIrradiance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maxObservedIrradiance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maxObservedIrradiance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maxObservedIrradiance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_maxObservedIrradiance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_maxObservedIrradiance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_maxObservedIrradiance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_maxObservedIrradiance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->maxObservedIrradiance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t exposures_lengthT = *(inbuffer + offset++);
      if(exposures_lengthT > exposures_length)
        this->exposures = (image_exposure_msgs::ImageExposureStatistics*)realloc(this->exposures, exposures_lengthT * sizeof(image_exposure_msgs::ImageExposureStatistics));
      offset += 3;
      exposures_length = exposures_lengthT;
      for( uint8_t i = 0; i < exposures_length; i++){
      offset += this->st_exposures.deserialize(inbuffer + offset);
        memcpy( &(this->exposures[i]), &(this->st_exposures), sizeof(image_exposure_msgs::ImageExposureStatistics));
      }
      this->underExposed =  ((uint32_t) (*(inbuffer + offset)));
      this->underExposed |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->underExposed |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->underExposed |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->underExposed);
      this->overExposed =  ((uint32_t) (*(inbuffer + offset)));
      this->overExposed |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->overExposed |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->overExposed |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->overExposed);
      union {
        double real;
        uint64_t base;
      } u_meanIrradiance;
      u_meanIrradiance.base = 0;
      u_meanIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_meanIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_meanIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_meanIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_meanIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_meanIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_meanIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_meanIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->meanIrradiance = u_meanIrradiance.real;
      offset += sizeof(this->meanIrradiance);
      union {
        double real;
        uint64_t base;
      } u_minMeasurableIrradiance;
      u_minMeasurableIrradiance.base = 0;
      u_minMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_minMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_minMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_minMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_minMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_minMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_minMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_minMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->minMeasurableIrradiance = u_minMeasurableIrradiance.real;
      offset += sizeof(this->minMeasurableIrradiance);
      union {
        double real;
        uint64_t base;
      } u_maxMeasurableIrradiance;
      u_maxMeasurableIrradiance.base = 0;
      u_maxMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maxMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maxMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maxMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_maxMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_maxMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_maxMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_maxMeasurableIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->maxMeasurableIrradiance = u_maxMeasurableIrradiance.real;
      offset += sizeof(this->maxMeasurableIrradiance);
      union {
        double real;
        uint64_t base;
      } u_minObservedIrradiance;
      u_minObservedIrradiance.base = 0;
      u_minObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_minObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_minObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_minObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_minObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_minObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_minObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_minObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->minObservedIrradiance = u_minObservedIrradiance.real;
      offset += sizeof(this->minObservedIrradiance);
      union {
        double real;
        uint64_t base;
      } u_maxObservedIrradiance;
      u_maxObservedIrradiance.base = 0;
      u_maxObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maxObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maxObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maxObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_maxObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_maxObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_maxObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_maxObservedIrradiance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->maxObservedIrradiance = u_maxObservedIrradiance.real;
      offset += sizeof(this->maxObservedIrradiance);
     return offset;
    }

    const char * getType(){ return "image_exposure_msgs/SequenceExposureStatistics"; };
    const char * getMD5(){ return "2a4f3187c50e7b3544984e9e28ce4328"; };

  };

}
#endif