#ifndef _ROS_frontier_exploration_ExploreTaskResult_h
#define _ROS_frontier_exploration_ExploreTaskResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace frontier_exploration
{

  class ExploreTaskResult : public ros::Msg
  {
    public:

    ExploreTaskResult()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "frontier_exploration/ExploreTaskResult"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif