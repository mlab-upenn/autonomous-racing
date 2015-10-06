#ifndef _ROS_pr2_mechanism_msgs_ActuatorStatistics_h
#define _ROS_pr2_mechanism_msgs_ActuatorStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace pr2_mechanism_msgs
{

  class ActuatorStatistics : public ros::Msg
  {
    public:
      const char* name;
      int32_t device_id;
      ros::Time timestamp;
      int32_t encoder_count;
      double encoder_offset;
      double position;
      double encoder_velocity;
      double velocity;
      bool calibration_reading;
      bool calibration_rising_edge_valid;
      bool calibration_falling_edge_valid;
      double last_calibration_rising_edge;
      double last_calibration_falling_edge;
      bool is_enabled;
      bool halted;
      double last_commanded_current;
      double last_commanded_effort;
      double last_executed_current;
      double last_executed_effort;
      double last_measured_current;
      double last_measured_effort;
      double motor_voltage;
      int32_t num_encoder_errors;

    ActuatorStatistics():
      name(""),
      device_id(0),
      timestamp(),
      encoder_count(0),
      encoder_offset(0),
      position(0),
      encoder_velocity(0),
      velocity(0),
      calibration_reading(0),
      calibration_rising_edge_valid(0),
      calibration_falling_edge_valid(0),
      last_calibration_rising_edge(0),
      last_calibration_falling_edge(0),
      is_enabled(0),
      halted(0),
      last_commanded_current(0),
      last_commanded_effort(0),
      last_executed_current(0),
      last_executed_effort(0),
      last_measured_current(0),
      last_measured_effort(0),
      motor_voltage(0),
      num_encoder_errors(0)
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
      union {
        int32_t real;
        uint32_t base;
      } u_device_id;
      u_device_id.real = this->device_id;
      *(outbuffer + offset + 0) = (u_device_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_device_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_device_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_device_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->device_id);
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
        int32_t real;
        uint32_t base;
      } u_encoder_count;
      u_encoder_count.real = this->encoder_count;
      *(outbuffer + offset + 0) = (u_encoder_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_count);
      union {
        double real;
        uint64_t base;
      } u_encoder_offset;
      u_encoder_offset.real = this->encoder_offset;
      *(outbuffer + offset + 0) = (u_encoder_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_offset.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_encoder_offset.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_encoder_offset.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_encoder_offset.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_encoder_offset.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->encoder_offset);
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
      } u_encoder_velocity;
      u_encoder_velocity.real = this->encoder_velocity;
      *(outbuffer + offset + 0) = (u_encoder_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_velocity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_encoder_velocity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_encoder_velocity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_encoder_velocity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_encoder_velocity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->encoder_velocity);
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
        bool real;
        uint8_t base;
      } u_calibration_reading;
      u_calibration_reading.real = this->calibration_reading;
      *(outbuffer + offset + 0) = (u_calibration_reading.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->calibration_reading);
      union {
        bool real;
        uint8_t base;
      } u_calibration_rising_edge_valid;
      u_calibration_rising_edge_valid.real = this->calibration_rising_edge_valid;
      *(outbuffer + offset + 0) = (u_calibration_rising_edge_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->calibration_rising_edge_valid);
      union {
        bool real;
        uint8_t base;
      } u_calibration_falling_edge_valid;
      u_calibration_falling_edge_valid.real = this->calibration_falling_edge_valid;
      *(outbuffer + offset + 0) = (u_calibration_falling_edge_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->calibration_falling_edge_valid);
      union {
        double real;
        uint64_t base;
      } u_last_calibration_rising_edge;
      u_last_calibration_rising_edge.real = this->last_calibration_rising_edge;
      *(outbuffer + offset + 0) = (u_last_calibration_rising_edge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_calibration_rising_edge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_calibration_rising_edge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_calibration_rising_edge.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_calibration_rising_edge.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_calibration_rising_edge.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_calibration_rising_edge.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_calibration_rising_edge.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_calibration_rising_edge);
      union {
        double real;
        uint64_t base;
      } u_last_calibration_falling_edge;
      u_last_calibration_falling_edge.real = this->last_calibration_falling_edge;
      *(outbuffer + offset + 0) = (u_last_calibration_falling_edge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_calibration_falling_edge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_calibration_falling_edge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_calibration_falling_edge.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_calibration_falling_edge.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_calibration_falling_edge.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_calibration_falling_edge.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_calibration_falling_edge.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_calibration_falling_edge);
      union {
        bool real;
        uint8_t base;
      } u_is_enabled;
      u_is_enabled.real = this->is_enabled;
      *(outbuffer + offset + 0) = (u_is_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_enabled);
      union {
        bool real;
        uint8_t base;
      } u_halted;
      u_halted.real = this->halted;
      *(outbuffer + offset + 0) = (u_halted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->halted);
      union {
        double real;
        uint64_t base;
      } u_last_commanded_current;
      u_last_commanded_current.real = this->last_commanded_current;
      *(outbuffer + offset + 0) = (u_last_commanded_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_commanded_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_commanded_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_commanded_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_commanded_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_commanded_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_commanded_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_commanded_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_commanded_current);
      union {
        double real;
        uint64_t base;
      } u_last_commanded_effort;
      u_last_commanded_effort.real = this->last_commanded_effort;
      *(outbuffer + offset + 0) = (u_last_commanded_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_commanded_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_commanded_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_commanded_effort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_commanded_effort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_commanded_effort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_commanded_effort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_commanded_effort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_commanded_effort);
      union {
        double real;
        uint64_t base;
      } u_last_executed_current;
      u_last_executed_current.real = this->last_executed_current;
      *(outbuffer + offset + 0) = (u_last_executed_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_executed_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_executed_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_executed_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_executed_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_executed_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_executed_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_executed_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_executed_current);
      union {
        double real;
        uint64_t base;
      } u_last_executed_effort;
      u_last_executed_effort.real = this->last_executed_effort;
      *(outbuffer + offset + 0) = (u_last_executed_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_executed_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_executed_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_executed_effort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_executed_effort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_executed_effort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_executed_effort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_executed_effort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_executed_effort);
      union {
        double real;
        uint64_t base;
      } u_last_measured_current;
      u_last_measured_current.real = this->last_measured_current;
      *(outbuffer + offset + 0) = (u_last_measured_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_measured_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_measured_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_measured_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_measured_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_measured_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_measured_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_measured_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_measured_current);
      union {
        double real;
        uint64_t base;
      } u_last_measured_effort;
      u_last_measured_effort.real = this->last_measured_effort;
      *(outbuffer + offset + 0) = (u_last_measured_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_last_measured_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_last_measured_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_last_measured_effort.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_last_measured_effort.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_last_measured_effort.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_last_measured_effort.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_last_measured_effort.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->last_measured_effort);
      union {
        double real;
        uint64_t base;
      } u_motor_voltage;
      u_motor_voltage.real = this->motor_voltage;
      *(outbuffer + offset + 0) = (u_motor_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_motor_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_motor_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_motor_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_motor_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->motor_voltage);
      union {
        int32_t real;
        uint32_t base;
      } u_num_encoder_errors;
      u_num_encoder_errors.real = this->num_encoder_errors;
      *(outbuffer + offset + 0) = (u_num_encoder_errors.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_encoder_errors.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_encoder_errors.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_encoder_errors.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_encoder_errors);
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
      union {
        int32_t real;
        uint32_t base;
      } u_device_id;
      u_device_id.base = 0;
      u_device_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_device_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_device_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_device_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->device_id = u_device_id.real;
      offset += sizeof(this->device_id);
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
        int32_t real;
        uint32_t base;
      } u_encoder_count;
      u_encoder_count.base = 0;
      u_encoder_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->encoder_count = u_encoder_count.real;
      offset += sizeof(this->encoder_count);
      union {
        double real;
        uint64_t base;
      } u_encoder_offset;
      u_encoder_offset.base = 0;
      u_encoder_offset.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_offset.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_offset.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_offset.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_encoder_offset.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_encoder_offset.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_encoder_offset.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_encoder_offset.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->encoder_offset = u_encoder_offset.real;
      offset += sizeof(this->encoder_offset);
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
      } u_encoder_velocity;
      u_encoder_velocity.base = 0;
      u_encoder_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_encoder_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_encoder_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_encoder_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_encoder_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_encoder_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_encoder_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_encoder_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->encoder_velocity = u_encoder_velocity.real;
      offset += sizeof(this->encoder_velocity);
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
        bool real;
        uint8_t base;
      } u_calibration_reading;
      u_calibration_reading.base = 0;
      u_calibration_reading.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->calibration_reading = u_calibration_reading.real;
      offset += sizeof(this->calibration_reading);
      union {
        bool real;
        uint8_t base;
      } u_calibration_rising_edge_valid;
      u_calibration_rising_edge_valid.base = 0;
      u_calibration_rising_edge_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->calibration_rising_edge_valid = u_calibration_rising_edge_valid.real;
      offset += sizeof(this->calibration_rising_edge_valid);
      union {
        bool real;
        uint8_t base;
      } u_calibration_falling_edge_valid;
      u_calibration_falling_edge_valid.base = 0;
      u_calibration_falling_edge_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->calibration_falling_edge_valid = u_calibration_falling_edge_valid.real;
      offset += sizeof(this->calibration_falling_edge_valid);
      union {
        double real;
        uint64_t base;
      } u_last_calibration_rising_edge;
      u_last_calibration_rising_edge.base = 0;
      u_last_calibration_rising_edge.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_calibration_rising_edge.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_calibration_rising_edge.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_calibration_rising_edge.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_calibration_rising_edge.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_calibration_rising_edge.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_calibration_rising_edge.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_calibration_rising_edge.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_calibration_rising_edge = u_last_calibration_rising_edge.real;
      offset += sizeof(this->last_calibration_rising_edge);
      union {
        double real;
        uint64_t base;
      } u_last_calibration_falling_edge;
      u_last_calibration_falling_edge.base = 0;
      u_last_calibration_falling_edge.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_calibration_falling_edge.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_calibration_falling_edge.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_calibration_falling_edge.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_calibration_falling_edge.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_calibration_falling_edge.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_calibration_falling_edge.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_calibration_falling_edge.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_calibration_falling_edge = u_last_calibration_falling_edge.real;
      offset += sizeof(this->last_calibration_falling_edge);
      union {
        bool real;
        uint8_t base;
      } u_is_enabled;
      u_is_enabled.base = 0;
      u_is_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_enabled = u_is_enabled.real;
      offset += sizeof(this->is_enabled);
      union {
        bool real;
        uint8_t base;
      } u_halted;
      u_halted.base = 0;
      u_halted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->halted = u_halted.real;
      offset += sizeof(this->halted);
      union {
        double real;
        uint64_t base;
      } u_last_commanded_current;
      u_last_commanded_current.base = 0;
      u_last_commanded_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_commanded_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_commanded_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_commanded_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_commanded_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_commanded_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_commanded_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_commanded_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_commanded_current = u_last_commanded_current.real;
      offset += sizeof(this->last_commanded_current);
      union {
        double real;
        uint64_t base;
      } u_last_commanded_effort;
      u_last_commanded_effort.base = 0;
      u_last_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_commanded_effort = u_last_commanded_effort.real;
      offset += sizeof(this->last_commanded_effort);
      union {
        double real;
        uint64_t base;
      } u_last_executed_current;
      u_last_executed_current.base = 0;
      u_last_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_executed_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_executed_current = u_last_executed_current.real;
      offset += sizeof(this->last_executed_current);
      union {
        double real;
        uint64_t base;
      } u_last_executed_effort;
      u_last_executed_effort.base = 0;
      u_last_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_executed_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_executed_effort = u_last_executed_effort.real;
      offset += sizeof(this->last_executed_effort);
      union {
        double real;
        uint64_t base;
      } u_last_measured_current;
      u_last_measured_current.base = 0;
      u_last_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_measured_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_measured_current = u_last_measured_current.real;
      offset += sizeof(this->last_measured_current);
      union {
        double real;
        uint64_t base;
      } u_last_measured_effort;
      u_last_measured_effort.base = 0;
      u_last_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_last_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_last_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_last_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_last_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_last_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_last_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_last_measured_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->last_measured_effort = u_last_measured_effort.real;
      offset += sizeof(this->last_measured_effort);
      union {
        double real;
        uint64_t base;
      } u_motor_voltage;
      u_motor_voltage.base = 0;
      u_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_motor_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->motor_voltage = u_motor_voltage.real;
      offset += sizeof(this->motor_voltage);
      union {
        int32_t real;
        uint32_t base;
      } u_num_encoder_errors;
      u_num_encoder_errors.base = 0;
      u_num_encoder_errors.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_encoder_errors.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_encoder_errors.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_encoder_errors.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_encoder_errors = u_num_encoder_errors.real;
      offset += sizeof(this->num_encoder_errors);
     return offset;
    }

    const char * getType(){ return "pr2_mechanism_msgs/ActuatorStatistics"; };
    const char * getMD5(){ return "c37184273b29627de29382f1d3670175"; };

  };

}
#endif