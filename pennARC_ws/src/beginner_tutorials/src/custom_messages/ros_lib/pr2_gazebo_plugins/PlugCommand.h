#ifndef _ROS_pr2_gazebo_plugins_PlugCommand_h
#define _ROS_pr2_gazebo_plugins_PlugCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_gazebo_plugins
{

  class PlugCommand : public ros::Msg
  {
    public:
      bool ac_present;
      double charge_rate;
      double discharge_rate;
      double charge;

    PlugCommand():
      ac_present(0),
      charge_rate(0),
      discharge_rate(0),
      charge(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ac_present;
      u_ac_present.real = this->ac_present;
      *(outbuffer + offset + 0) = (u_ac_present.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ac_present);
      union {
        double real;
        uint64_t base;
      } u_charge_rate;
      u_charge_rate.real = this->charge_rate;
      *(outbuffer + offset + 0) = (u_charge_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_charge_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_charge_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_charge_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_charge_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->charge_rate);
      union {
        double real;
        uint64_t base;
      } u_discharge_rate;
      u_discharge_rate.real = this->discharge_rate;
      *(outbuffer + offset + 0) = (u_discharge_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_discharge_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_discharge_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_discharge_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_discharge_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_discharge_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_discharge_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_discharge_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->discharge_rate);
      union {
        double real;
        uint64_t base;
      } u_charge;
      u_charge.real = this->charge;
      *(outbuffer + offset + 0) = (u_charge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_charge.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_charge.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_charge.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_charge.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->charge);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ac_present;
      u_ac_present.base = 0;
      u_ac_present.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ac_present = u_ac_present.real;
      offset += sizeof(this->ac_present);
      union {
        double real;
        uint64_t base;
      } u_charge_rate;
      u_charge_rate.base = 0;
      u_charge_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_charge_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_charge_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_charge_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_charge_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->charge_rate = u_charge_rate.real;
      offset += sizeof(this->charge_rate);
      union {
        double real;
        uint64_t base;
      } u_discharge_rate;
      u_discharge_rate.base = 0;
      u_discharge_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_discharge_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_discharge_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_discharge_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_discharge_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_discharge_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_discharge_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_discharge_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->discharge_rate = u_discharge_rate.real;
      offset += sizeof(this->discharge_rate);
      union {
        double real;
        uint64_t base;
      } u_charge;
      u_charge.base = 0;
      u_charge.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_charge.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_charge.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_charge.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_charge.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->charge = u_charge.real;
      offset += sizeof(this->charge);
     return offset;
    }

    const char * getType(){ return "pr2_gazebo_plugins/PlugCommand"; };
    const char * getMD5(){ return "852b7035ee3e7fa6390824cf7b7e6dd1"; };

  };

}
#endif