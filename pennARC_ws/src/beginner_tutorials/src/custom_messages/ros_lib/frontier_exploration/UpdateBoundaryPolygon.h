#ifndef _ROS_SERVICE_UpdateBoundaryPolygon_h
#define _ROS_SERVICE_UpdateBoundaryPolygon_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"

namespace frontier_exploration
{

static const char UPDATEBOUNDARYPOLYGON[] = "frontier_exploration/UpdateBoundaryPolygon";

  class UpdateBoundaryPolygonRequest : public ros::Msg
  {
    public:
      geometry_msgs::PolygonStamped explore_boundary;

    UpdateBoundaryPolygonRequest():
      explore_boundary()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->explore_boundary.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->explore_boundary.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return UPDATEBOUNDARYPOLYGON; };
    const char * getMD5(){ return "fcd73e86a17cffec115813ce5a863c84"; };

  };

  class UpdateBoundaryPolygonResponse : public ros::Msg
  {
    public:

    UpdateBoundaryPolygonResponse()
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

    const char * getType(){ return UPDATEBOUNDARYPOLYGON; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class UpdateBoundaryPolygon {
    public:
    typedef UpdateBoundaryPolygonRequest Request;
    typedef UpdateBoundaryPolygonResponse Response;
  };

}
#endif
