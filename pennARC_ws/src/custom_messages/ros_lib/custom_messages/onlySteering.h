#ifndef _ROS_custom_messages_onlySteering_h
#define _ROS_custom_messages_onlySteering_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Int16.h"

namespace custom_messages
{

  class onlySteering : public ros::Msg
  {
    public:
      std_msgs::Int16 steering;

    onlySteering():
      steering()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->steering.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->steering.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "custom_messages/onlySteering"; };
    const char * getMD5(){ return "5aea1dc3f2cc7a185cd4f6a869edf20e"; };

  };

}
#endif