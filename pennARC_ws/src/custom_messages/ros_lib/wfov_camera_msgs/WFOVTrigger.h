#ifndef _ROS_wfov_camera_msgs_WFOVTrigger_h
#define _ROS_wfov_camera_msgs_WFOVTrigger_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"

namespace wfov_camera_msgs
{

  class WFOVTrigger : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* time_reference;
      ros::Time trigger_time;
      const char* trigger_time_reference;
      uint32_t shutter;
      uint32_t id;
      uint32_t trigger_seq;

    WFOVTrigger():
      header(),
      time_reference(""),
      trigger_time(),
      trigger_time_reference(""),
      shutter(0),
      id(0),
      trigger_seq(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_time_reference = strlen(this->time_reference);
      memcpy(outbuffer + offset, &length_time_reference, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->time_reference, length_time_reference);
      offset += length_time_reference;
      *(outbuffer + offset + 0) = (this->trigger_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trigger_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trigger_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trigger_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trigger_time.sec);
      *(outbuffer + offset + 0) = (this->trigger_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trigger_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trigger_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trigger_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trigger_time.nsec);
      uint32_t length_trigger_time_reference = strlen(this->trigger_time_reference);
      memcpy(outbuffer + offset, &length_trigger_time_reference, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->trigger_time_reference, length_trigger_time_reference);
      offset += length_trigger_time_reference;
      *(outbuffer + offset + 0) = (this->shutter >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shutter >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shutter >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shutter >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shutter);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->trigger_seq >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trigger_seq >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trigger_seq >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trigger_seq >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trigger_seq);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_time_reference;
      memcpy(&length_time_reference, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_time_reference; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_time_reference-1]=0;
      this->time_reference = (char *)(inbuffer + offset-1);
      offset += length_time_reference;
      this->trigger_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->trigger_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trigger_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trigger_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trigger_time.sec);
      this->trigger_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->trigger_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trigger_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trigger_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trigger_time.nsec);
      uint32_t length_trigger_time_reference;
      memcpy(&length_trigger_time_reference, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_trigger_time_reference; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_trigger_time_reference-1]=0;
      this->trigger_time_reference = (char *)(inbuffer + offset-1);
      offset += length_trigger_time_reference;
      this->shutter =  ((uint32_t) (*(inbuffer + offset)));
      this->shutter |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->shutter |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->shutter |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->shutter);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->trigger_seq =  ((uint32_t) (*(inbuffer + offset)));
      this->trigger_seq |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trigger_seq |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trigger_seq |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trigger_seq);
     return offset;
    }

    const char * getType(){ return "wfov_camera_msgs/WFOVTrigger"; };
    const char * getMD5(){ return "e38c040150f1be3148468f6b9974f8bf"; };

  };

}
#endif