#ifndef _ROS_SERVICE_GetInteractions_h
#define _ROS_SERVICE_GetInteractions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_interaction_msgs/Interaction.h"

namespace rocon_interaction_msgs
{

static const char GETINTERACTIONS[] = "rocon_interaction_msgs/GetInteractions";

  class GetInteractionsRequest : public ros::Msg
  {
    public:
      uint8_t roles_length;
      char* st_roles;
      char* * roles;
      const char* uri;

    GetInteractionsRequest():
      roles_length(0), roles(NULL),
      uri("")
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

    const char * getType(){ return GETINTERACTIONS; };
    const char * getMD5(){ return "7729678b2d98f5eb8e7358aaf9d23bcb"; };

  };

  class GetInteractionsResponse : public ros::Msg
  {
    public:
      uint8_t interactions_length;
      rocon_interaction_msgs::Interaction st_interactions;
      rocon_interaction_msgs::Interaction * interactions;

    GetInteractionsResponse():
      interactions_length(0), interactions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = interactions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < interactions_length; i++){
      offset += this->interactions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t interactions_lengthT = *(inbuffer + offset++);
      if(interactions_lengthT > interactions_length)
        this->interactions = (rocon_interaction_msgs::Interaction*)realloc(this->interactions, interactions_lengthT * sizeof(rocon_interaction_msgs::Interaction));
      offset += 3;
      interactions_length = interactions_lengthT;
      for( uint8_t i = 0; i < interactions_length; i++){
      offset += this->st_interactions.deserialize(inbuffer + offset);
        memcpy( &(this->interactions[i]), &(this->st_interactions), sizeof(rocon_interaction_msgs::Interaction));
      }
     return offset;
    }

    const char * getType(){ return GETINTERACTIONS; };
    const char * getMD5(){ return "b53200c67a1f2b4ced2b8771b7d14a13"; };

  };

  class GetInteractions {
    public:
    typedef GetInteractionsRequest Request;
    typedef GetInteractionsResponse Response;
  };

}
#endif
