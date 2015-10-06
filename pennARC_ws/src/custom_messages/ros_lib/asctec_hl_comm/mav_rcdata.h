#ifndef _ROS_asctec_hl_comm_mav_rcdata_h
#define _ROS_asctec_hl_comm_mav_rcdata_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace asctec_hl_comm
{

  class mav_rcdata : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t channel[8];

    mav_rcdata():
      header(),
      channel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 8; i++){
      *(outbuffer + offset + 0) = (this->channel[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channel[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->channel[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 8; i++){
      this->channel[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->channel[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->channel[i]);
      }
     return offset;
    }

    const char * getType(){ return "asctec_hl_comm/mav_rcdata"; };
    const char * getMD5(){ return "2511326b0deceba64dcfc173bba8678e"; };

  };

}
#endif