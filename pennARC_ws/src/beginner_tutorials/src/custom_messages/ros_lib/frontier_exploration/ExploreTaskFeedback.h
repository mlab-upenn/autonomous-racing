#ifndef _ROS_frontier_exploration_ExploreTaskFeedback_h
#define _ROS_frontier_exploration_ExploreTaskFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace frontier_exploration
{

  class ExploreTaskFeedback : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped next_frontier;
      geometry_msgs::PoseStamped base_position;

    ExploreTaskFeedback():
      next_frontier(),
      base_position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->next_frontier.serialize(outbuffer + offset);
      offset += this->base_position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->next_frontier.deserialize(inbuffer + offset);
      offset += this->base_position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "frontier_exploration/ExploreTaskFeedback"; };
    const char * getMD5(){ return "00baaad5b6065fdad0f528586c3caaf2"; };

  };

}
#endif