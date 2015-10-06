#ifndef _ROS_SERVICE_GetCameraRegisters_h
#define _ROS_SERVICE_GetCameraRegisters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace camera1394
{

static const char GETCAMERAREGISTERS[] = "camera1394/GetCameraRegisters";

  class GetCameraRegistersRequest : public ros::Msg
  {
    public:
      uint8_t type;
      uint64_t offset;
      uint32_t num_regs;
      uint32_t mode;
      enum { TYPE_CONTROL = 0 };
      enum { TYPE_ABSOLUTE = 1 };
      enum { TYPE_FORMAT7 = 2 };
      enum { TYPE_ADVANCED_CONTROL = 3 };
      enum { TYPE_PIO = 4 };
      enum { TYPE_SIO = 5 };
      enum { TYPE_STROBE = 6 };

    GetCameraRegistersRequest():
      type(0),
      offset(0),
      num_regs(0),
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
      *(outbuffer + offset + 0) = (this->num_regs >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_regs >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_regs >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_regs >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_regs);
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
      this->num_regs =  ((uint32_t) (*(inbuffer + offset)));
      this->num_regs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_regs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_regs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_regs);
      this->mode =  ((uint32_t) (*(inbuffer + offset)));
      this->mode |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mode |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mode |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mode);
     return offset;
    }

    const char * getType(){ return GETCAMERAREGISTERS; };
    const char * getMD5(){ return "3899ed32cc2bf9b6257abe5965b09162"; };

  };

  class GetCameraRegistersResponse : public ros::Msg
  {
    public:
      uint8_t value_length;
      uint32_t st_value;
      uint32_t * value;

    GetCameraRegistersResponse():
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
     return offset;
    }

    const char * getType(){ return GETCAMERAREGISTERS; };
    const char * getMD5(){ return "4680a08e992f8f11add4bc58e31c78a7"; };

  };

  class GetCameraRegisters {
    public:
    typedef GetCameraRegistersRequest Request;
    typedef GetCameraRegistersResponse Response;
  };

}
#endif
