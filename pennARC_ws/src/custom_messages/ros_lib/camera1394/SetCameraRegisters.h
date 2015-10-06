#ifndef _ROS_SERVICE_SetCameraRegisters_h
#define _ROS_SERVICE_SetCameraRegisters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace camera1394
{

static const char SETCAMERAREGISTERS[] = "camera1394/SetCameraRegisters";

  class SetCameraRegistersRequest : public ros::Msg
  {
    public:
      uint8_t type;
      uint64_t offset;
      uint8_t value_length;
      uint32_t st_value;
      uint32_t * value;
      uint32_t mode;
      enum { TYPE_CONTROL = 0 };
      enum { TYPE_ABSOLUTE = 1 };
      enum { TYPE_FORMAT7 = 2 };
      enum { TYPE_ADVANCED_CONTROL = 3 };
      enum { TYPE_PIO = 4 };
      enum { TYPE_SIO = 5 };
      enum { TYPE_STROBE = 6 };

    SetCameraRegistersRequest():
      type(0),
      offset(0),
      value_length(0), value(NULL),
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->offset >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->offset >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->offset >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->offset >> (8 * 7)) & 0xFF;
      offset += sizeof(this->offset);
      *(outbuffer + offset++) = value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value_length; i++){
      *(outbuffer + offset + 0) = (this->value[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value[i]);
      }
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mode >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mode >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mode >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->offset =  ((uint64_t) (*(inbuffer + offset)));
      this->offset |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->offset |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->offset |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->offset |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->offset |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->offset |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->offset |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->offset);
      uint8_t value_lengthT = *(inbuffer + offset++);
      if(value_lengthT > value_length)
        this->value = (uint32_t*)realloc(this->value, value_lengthT * sizeof(uint32_t));
      offset += 3;
      value_length = value_lengthT;
      for( uint8_t i = 0; i < value_length; i++){
      this->st_value =  ((uint32_t) (*(inbuffer + offset)));
      this->st_value |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_value |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_value |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(uint32_t));
      }
      this->mode =  ((uint32_t) (*(inbuffer + offset)));
      this->mode |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mode |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mode |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mode);
     return offset;
    }

    const char * getType(){ return SETCAMERAREGISTERS; };
    const char * getMD5(){ return "703211788a5d6f08f820dfb1792ab51c"; };

  };

  class SetCameraRegistersResponse : public ros::Msg
  {
    public:

    SetCameraRegistersResponse()
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

    const char * getType(){ return SETCAMERAREGISTERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetCameraRegisters {
    public:
    typedef SetCameraRegistersRequest Request;
    typedef SetCameraRegistersResponse Response;
  };

}
#endif
