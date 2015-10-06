#ifndef _ROS_frontier_exploration_ExploreTaskActionFeedback_h
#define _ROS_frontier_exploration_ExploreTaskActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "frontier_exploration/ExploreTaskFeedback.h"

namespace frontier_exploration
{

  class ExploreTaskActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      frontier_exploration::ExploreTaskFeedback feedback;

    ExploreTaskActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "frontier_exploration/ExploreTaskActionFeedback"; };
    const char * getMD5(){ return "11b891614a80e5279e0720e16a4e4612"; };

  };

}
#endif