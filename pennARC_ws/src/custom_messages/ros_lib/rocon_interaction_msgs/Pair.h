#ifndef _ROS_rocon_interaction_msgs_Pair_h
#define _ROS_rocon_interaction_msgs_Pair_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_interaction_msgs
{

  class Pair : public ros::Msg
  {
    public:
      const char* rapp;
      const char* remocon;

    Pair():
      rapp(""),
      remocon("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_rapp = strlen(this->rapp);
      memcpy(outbuffer + offset, &length_rapp, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rapp, length_rapp);
      offset += length_rapp;
      uint32_t length_remocon = strlen(this->remocon);
      memcpy(outbuffer + offset, &length_remocon, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->remocon, length_remocon);
      offset += length_remocon;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_rapp;
      memcpy(&length_rapp, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rapp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rapp-1]=0;
      this->rapp = (char *)(inbuffer + offset-1);
      offset += length_rapp;
      uint32_t length_remocon;
      memcpy(&length_remocon, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_remocon; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_remocon-1]=0;
      this->remocon = (char *)(inbuffer + offset-1);
      offset += length_remocon;
     return offset;
    }

    const char * getType(){ return "rocon_interaction_msgs/Pair"; };
    const char * getMD5(){ return "eee13ef64ff35326a7c0b99255f90428"; };

  };

}
#endif