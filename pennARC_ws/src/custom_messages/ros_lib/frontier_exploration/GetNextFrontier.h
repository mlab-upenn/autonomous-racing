#ifndef _ROS_SERVICE_GetNextFrontier_h
#define _ROS_SERVICE_GetNextFrontier_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace frontier_exploration
{

static const char GETNEXTFRONTIER[] = "frontier_exploration/GetNextFrontier";

  class GetNextFrontierRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped start_pose;

    GetNextFrontierRequest():
      start_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->start_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->start_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETNEXTFRONTIER; };
    const char * getMD5(){ return "5b059506b52a2ec83de1e33422377a1b"; };

  };

  class GetNextFrontierResponse : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped next_frontier;

    GetNextFrontierResponse():
      next_frontier()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->next_frontier.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->next_frontier.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETNEXTFRONTIER; };
    const char * getMD5(){ return "df2ac5789785e819aa300966fa36644e"; };

  };

  class GetNextFrontier {
    public:
    typedef GetNextFrontierRequest Request;
    typedef GetNextFrontierResponse Response;
  };

}
#endif
