#ifndef _ROS_custom_messages_driveMessage2_h
#define _ROS_custom_messages_driveMessage2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Int16.h"

namespace custom_messages
{

  class driveMessage2 : public ros::Msg
  {
    public:
      std_msgs::Int16 steering;
      std_msgs::Int16 throttle;

    driveMessage2():
      steering(),
      throttle()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->steering.serialize(outbuffer + offset);
      offset += this->throttle.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->steering.deserialize(inbuffer + offset);
      offset += this->throttle.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "custom_messages/driveMessage2"; };
    const char * getMD5(){ return "a69c0060aefd939bbb5005d276d57d59"; };

  };

}
#endif