#ifndef _ROS_pr2_mechanism_msgs_JointStatistics_h
#define _ROS_pr2_mechanism_msgs_JointStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace pr2_mechanism_msgs
{

  class JointStatistics : public ros::Msg
  {
    public:
      const char* name;
      ros::Time timestamp;
      double position;
      double velocity;
      double measured_effort;
      double commanded_effort;
      bool is_calibrated;
      bool violated_limits;
      double odometer;
      double min_position;
      double max_position;
      double max_abs_velocity;
      double max_abs_effort;

    JointStatistics():
      name(""),
      timestamp(),
      position(0),
      velocity(0),
      measured_effort(0),
      commanded_effort(0),
      is_calibrated(0),
      violated_limits(0),
      odometer(0),
      min_position(0),
      max_position(0),
      max_abs_velocity(0),
      max_abs_effort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->timestamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.sec);
      *(outbuffer + offset + 0) = (this->timestamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.nsec);
      union {
        double real;
        uint64_t base;
      } u_position;
      u_position.real = this->position;
      *(outbuffer + offset + 0) = (u_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position);
      union {
        double real;
        uint64_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        double real;
        uint64_t base;
      } u_measured_effort;
      u_measured_effort.real = this->measured_effort;
      *(outbuffer + offset + 0) = (u_measured_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measured_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measured_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measured_effort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_measured_effort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_measured_effort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_measured_effort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_measured_effort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->measured_effort);
      union {
        double real;
        uint64_t base;
      } u_commanded_effort;
      u_commanded_effort.real = this->commanded_effort;
      *(outbuffer + offset + 0) = (u_commanded_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commanded_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commanded_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commanded_effort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_commanded_effort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_commanded_effort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_commanded_effort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_commanded_effort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->commanded_effort);
      union {
        bool real;
        uint8_t base;
      } u_is_calibrated;
      u_is_calibrated.real = this->is_calibrated;
      *(outbuffer + offset + 0) = (u_is_calibrated.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_calibrated);
      union {
        bool real;
        uint8_t base;
      } u_violated_limits;
      u_violated_limits.real = this->violated_limits;
      *(outbuffer + offset + 0) = (u_violated_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->violated_limits);
      union {
        double real;
        uint64_t base;
      } u_odometer;
      u_odometer.real = this->odometer;
      *(outbuffer + offset + 0) = (u_odometer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odometer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_odometer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_odometer.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_odometer.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_odometer.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_odometer.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_odometer.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->odometer);
      union {
        double real;
        uint64_t base;
      } u_min_position;
      u_min_position.real = this->min_position;
      *(outbuffer + offset + 0) = (u_min_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_min_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_min_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_min_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_min_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->min_position);
      union {
        double real;
        uint64_t base;
      } u_max_position;
      u_max_position.real = this->max_position;
      *(outbuffer + offset + 0) = (u_max_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_position.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_position.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_position.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_position.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_position.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_position);
      union {
        double real;
        uint64_t base;
      } u_max_abs_velocity;
      u_max_abs_velocity.real = this->max_abs_velocity;
      *(outbuffer + offset + 0) = (u_max_abs_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_abs_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_abs_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_abs_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_abs_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_abs_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_abs_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_abs_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_abs_velocity);
      union {
        double real;
        uint64_t base;
      } u_max_abs_effort;
      u_max_abs_effort.real = this->max_abs_effort;
      *(outbuffer + offset + 0) = (u_max_abs_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_abs_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_abs_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_abs_effort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_abs_effort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_abs_effort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_abs_effort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_abs_effort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_abs_effort);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->timestamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.sec);
      this->timestamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.nsec);
      union {
        double real;
        uint64_t base;
      } u_position;
      u_position.base = 0;
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->position = u_position.real;
      offset += sizeof(this->position);
      union {
        double real;
        uint64_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        double real;
        uint64_t base;
      } u_measured_effort;
      u_measured_effort.base = 0;
      u_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->measured_effort = u_measured_effort.real;
      offset += sizeof(this->measured_effort);
      union {
        double real;
        uint64_t base;
      } u_commanded_effort;
      u_commanded_effort.base = 0;
      u_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->commanded_effort = u_commanded_effort.real;
      offset += sizeof(this->commanded_effort);
      union {
        bool real;
        uint8_t base;
      } u_is_calibrated;
      u_is_calibrated.base = 0;
      u_is_calibrated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_calibrated = u_is_calibrated.real;
      offset += sizeof(this->is_calibrated);
      union {
        bool real;
        uint8_t base;
      } u_violated_limits;
      u_violated_limits.base = 0;
      u_violated_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->violated_limits = u_violated_limits.real;
      offset += sizeof(this->violated_limits);
      union {
        double real;
        uint64_t base;
      } u_odometer;
      u_odometer.base = 0;
      u_odometer.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odometer.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_odometer.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_odometer.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_odometer.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_odometer.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_odometer.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_odometer.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->odometer = u_odometer.real;
      offset += sizeof(this->odometer);
      union {
        double real;
        uint64_t base;
      } u_min_position;
      u_min_position.base = 0;
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_min_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->min_position = u_min_position.real;
      offset += sizeof(this->min_position);
      union {
        double real;
        uint64_t base;
      } u_max_position;
      u_max_position.base = 0;
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_position = u_max_position.real;
      offset += sizeof(this->max_position);
      union {
        double real;
        uint64_t base;
      } u_max_abs_velocity;
      u_max_abs_velocity.base = 0;
      u_max_abs_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_abs_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_abs_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_abs_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_abs_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_abs_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_abs_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_abs_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_abs_velocity = u_max_abs_velocity.real;
      offset += sizeof(this->max_abs_velocity);
      union {
        double real;
        uint64_t base;
      } u_max_abs_effort;
      u_max_abs_effort.base = 0;
      u_max_abs_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_abs_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_abs_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_abs_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_abs_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_abs_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_abs_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_abs_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_abs_effort = u_max_abs_effort.real;
      offset += sizeof(this->max_abs_effort);
     return offset;
    }

    const char * getType(){ return "pr2_mechanism_msgs/JointStatistics"; };
    const char * getMD5(){ return "90fdc8acbce5bc783d8b4aec49af6590"; };

  };

}
#endif