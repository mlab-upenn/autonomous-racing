#ifndef _ROS_SERVICE_GetRoles_h
#define _ROS_SERVICE_GetRoles_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_interaction_msgs
{

static const char GETROLES[] = "rocon_interaction_msgs/GetRoles";

  class GetRolesRequest : public ros::Msg
  {
    public:
      const char* uri;

    GetRolesRequest():
      uri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_uri = strlen(this->uri);
      memcpy(outbuffer + offset, &length_uri, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_uri;
      memcpy(&length_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
     return offset;
    }

    const char * getType(){ return GETROLES; };
    const char * getMD5(){ return "636fe5e07550f026d28388e95c38a9f4"; };

  };

  class GetRolesResponse : public ros::Msg
  {
    public:
      uint8_t roles_length;
      char* st_roles;
      char* * roles;

    GetRolesResponse():
      roles_length(0), roles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = roles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < roles_length; i++){
      uint32_t length_rolesi = strlen(this->roles[i]);
      memcpy(outbuffer + offset, &length_rolesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->roles[i], length_rolesi);
      offset += length_rolesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t roles_lengthT = *(inbuffer + offset++);
      if(roles_lengthT > roles_length)
        this->roles = (char**)realloc(this->roles, roles_lengthT * sizeof(char*));
      offset += 3;
      roles_length = roles_lengthT;
      for( uint8_t i = 0; i < roles_length; i++){
      uint32_t length_st_roles;
      memcpy(&length_st_roles, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_roles; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_roles-1]=0;
      this->st_roles = (char *)(inbuffer + offset-1);
      offset += length_st_roles;
        memcpy( &(this->roles[i]), &(this->st_roles), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return GETROLES; };
    const char * getMD5(){ return "ce55e2e9282b0c3ff724b153ff848a8a"; };

  };

  class GetRoles {
    public:
    typedef GetRolesRequest Request;
    typedef GetRolesResponse Response;
  };

}
#endif
