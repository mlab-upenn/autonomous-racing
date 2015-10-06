#ifndef _ROS_SERVICE_Wgs84ToEnu_h
#define _ROS_SERVICE_Wgs84ToEnu_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace asctec_hl_comm
{

static const char WGS84TOENU[] = "asctec_hl_comm/Wgs84ToEnu";

  class Wgs84ToEnuRequest : public ros::Msg
  {
    public:
      double lat;
      double lon;
      double alt;

    Wgs84ToEnuRequest():
      lat(0),
      lon(0),
      alt(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_lat;
      u_lat.real = this->lat;
      *(outbuffer + offset + 0) = (u_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lat);
      union {
        double real;
        uint64_t base;
      } u_lon;
      u_lon.real = this->lon;
      *(outbuffer + offset + 0) = (u_lon.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lon.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lon.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lon.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_lon.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_lon.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_lon.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_lon.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->lon);
      union {
        double real;
        uint64_t base;
      } u_alt;
      u_alt.real = this->alt;
      *(outbuffer + offset + 0) = (u_alt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alt.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_alt.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_alt.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_alt.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_alt.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->alt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_lat;
      u_lat.base = 0;
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lat = u_lat.real;
      offset += sizeof(this->lat);
      union {
        double real;
        uint64_t base;
      } u_lon;
      u_lon.base = 0;
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_lon.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->lon = u_lon.real;
      offset += sizeof(this->lon);
      union {
        double real;
        uint64_t base;
      } u_alt;
      u_alt.base = 0;
      u_alt.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alt.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alt.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alt.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_alt.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_alt.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_alt.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_alt.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->alt = u_alt.real;
      offset += sizeof(this->alt);
     return offset;
    }

    const char * getType(){ return WGS84TOENU; };
    const char * getMD5(){ return "800b265188e13fdc7e121024d9b6fa27"; };

  };

  class Wgs84ToEnuResponse : public ros::Msg
  {
    public:
      double x;
      double y;
      double z;

    Wgs84ToEnuResponse():
      x(0),
      y(0),
      z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->z = u_z.real;
      offset += sizeof(this->z);
     return offset;
    }

    const char * getType(){ return WGS84TOENU; };
    const char * getMD5(){ return "4a842b65f413084dc2b10fb484ea7f17"; };

  };

  class Wgs84ToEnu {
    public:
    typedef Wgs84ToEnuRequest Request;
    typedef Wgs84ToEnuResponse Response;
  };

}
#endif
