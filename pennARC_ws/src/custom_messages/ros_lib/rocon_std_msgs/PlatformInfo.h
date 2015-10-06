#ifndef _ROS_rocon_std_msgs_PlatformInfo_h
#define _ROS_rocon_std_msgs_PlatformInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/Icon.h"

namespace rocon_std_msgs
{

  class PlatformInfo : public ros::Msg
  {
    public:
      const char* uri;
      const char* version;
      rocon_std_msgs::Icon icon;

    PlatformInfo():
      uri(""),
      version(""),
      icon()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_uri = strlen(this->uri);
      memcpy(outbuffer + offset, &length_uri, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      uint32_t length_version = strlen(this->version);
      memcpy(outbuffer + offset, &length_version, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      offset += this->icon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_uri;
      memcpy(&length_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
      uint32_t length_version;
      memcpy(&length_version, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
      offset += this->icon.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rocon_std_msgs/PlatformInfo"; };
    const char * getMD5(){ return "ffe7bd3c68cda016b708f36a9d12b09e"; };

  };

}
#endif