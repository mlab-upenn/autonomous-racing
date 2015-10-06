#ifndef _ROS_pr2_gazebo_plugins_ModelJointsState_h
#define _ROS_pr2_gazebo_plugins_ModelJointsState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace pr2_gazebo_plugins
{

  class ModelJointsState : public ros::Msg
  {
    public:
      uint8_t model_pose_length;
      geometry_msgs::Pose st_model_pose;
      geometry_msgs::Pose * model_pose;
      uint8_t joint_names_length;
      char* st_joint_names;
      char* * joint_names;
      uint8_t joint_positions_length;
      double st_joint_positions;
      double * joint_positions;

    ModelJointsState():
      model_pose_length(0), model_pose(NULL),
      joint_names_length(0), joint_names(NULL),
      joint_positions_length(0), joint_positions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = model_pose_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < model_pose_length; i++){
      offset += this->model_pose[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = joint_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      memcpy(outbuffer + offset, &length_joint_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset++) = joint_positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_positions_length; i++){
      union {
        double real;
        uint64_t base;
      } u_joint_positionsi;
      u_joint_positionsi.real = this->joint_positions[i];
      *(outbuffer + offset + 0) = (u_joint_positionsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_joint_positionsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_joint_positionsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_joint_positionsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_joint_positionsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_joint_positionsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_joint_positionsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_joint_positionsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->joint_positions[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t model_pose_lengthT = *(inbuffer + offset++);
      if(model_pose_lengthT > model_pose_length)
        this->model_pose = (geometry_msgs::Pose*)realloc(this->model_pose, model_pose_lengthT * sizeof(geometry_msgs::Pose));
      offset += 3;
      model_pose_length = model_pose_lengthT;
      for( uint8_t i = 0; i < model_pose_length; i++){
      offset += this->st_model_pose.deserialize(inbuffer + offset);
        memcpy( &(this->model_pose[i]), &(this->st_model_pose), sizeof(geometry_msgs::Pose));
      }
      uint8_t joint_names_lengthT = *(inbuffer + offset++);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      offset += 3;
      joint_names_length = joint_names_lengthT;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      memcpy(&length_st_joint_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint8_t joint_positions_lengthT = *(inbuffer + offset++);
      if(joint_positions_lengthT > joint_positions_length)
        this->joint_positions = (double*)realloc(this->joint_positions, joint_positions_lengthT * sizeof(double));
      offset += 3;
      joint_positions_length = joint_positions_lengthT;
      for( uint8_t i = 0; i < joint_positions_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_joint_positions;
      u_st_joint_positions.base = 0;
      u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_joint_positions = u_st_joint_positions.real;
      offset += sizeof(this->st_joint_positions);
        memcpy( &(this->joint_positions[i]), &(this->st_joint_positions), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "pr2_gazebo_plugins/ModelJointsState"; };
    const char * getMD5(){ return "f700a74958b6566fae4cd77fbb80ffd4"; };

  };

}
#endif