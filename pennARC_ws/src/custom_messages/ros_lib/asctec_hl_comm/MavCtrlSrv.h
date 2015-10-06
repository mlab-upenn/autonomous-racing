#ifndef _ROS_SERVICE_MavCtrlSrv_h
#define _ROS_SERVICE_MavCtrlSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "asctec_hl_comm/mav_ctrl.h"

namespace asctec_hl_comm
{

static const char MAVCTRLSRV[] = "asctec_hl_comm/MavCtrlSrv";

  class MavCtrlSrvRequest : public ros::Msg
  {
    public:
      asctec_hl_comm::mav_ctrl ctrl;

    MavCtrlSrvRequest():
      ctrl()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->ctrl.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->ctrl.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MAVCTRLSRV; };
    const char * getMD5(){ return "38a627ff8fcd6d0f534f521aa37786af"; };

  };

  class MavCtrlSrvResponse : public ros::Msg
  {
    public:
      asctec_hl_comm::mav_ctrl ctrl_result;

    MavCtrlSrvResponse():
      ctrl_result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->ctrl_result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->ctrl_result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MAVCTRLSRV; };
    const char * getMD5(){ return "b903b08125ca08bbbb20320238af4215"; };

  };

  class MavCtrlSrv {
    public:
    typedef MavCtrlSrvRequest Request;
    typedef MavCtrlSrvResponse Response;
  };

}
#endif
