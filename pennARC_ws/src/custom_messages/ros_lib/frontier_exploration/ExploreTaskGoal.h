#ifndef _ROS_frontier_exploration_ExploreTaskGoal_h
#define _ROS_frontier_exploration_ExploreTaskGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"
#include "geometry_msgs/PointStamped.h"

namespace frontier_exploration
{

  class ExploreTaskGoal : public ros::Msg
  {
    public:
      geometry_msgs::PolygonStamped explore_boundary;
      geometry_msgs::PointStamped explore_center;

    ExploreTaskGoal():
      explore_boundary(),
      explore_center()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->explore_boundary.serialize(outbuffer + offset);
      offset += this->explore_center.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->explore_boundary.deserialize(inbuffer + offset);
      offset += this->explore_center.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "frontier_exploration/ExploreTaskGoal"; };
    const char * getMD5(){ return "b5f41b52fbca52a68ff7363f86187dbf"; };

  };

}
#endif