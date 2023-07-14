#ifndef _ROS_science_sensor_h
#define _ROS_science_sensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace science
{

  class sensor : public ros::Msg
  {
    public:
      typedef int32_t _ir_type;
      _ir_type ir;
      typedef int32_t _broadband_type;
      _broadband_type broadband;
      typedef float _bmp_temp_type;
      _bmp_temp_type bmp_temp;
      typedef float _bmp_pressure_type;
      _bmp_pressure_type bmp_pressure;
      typedef float _bmp_alt_type;
      _bmp_alt_type bmp_alt;
      typedef float _dht_humidity_type;
      _dht_humidity_type dht_humidity;
      typedef float _dht_temp_type;
      _dht_temp_type dht_temp;
      typedef float _ratio_type;
      _ratio_type ratio;

    sensor():
      ir(0),
      broadband(0),
      bmp_temp(0),
      bmp_pressure(0),
      bmp_alt(0),
      dht_humidity(0),
      dht_temp(0),
      ratio(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_ir;
      u_ir.real = this->ir;
      *(outbuffer + offset + 0) = (u_ir.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ir.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ir.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ir.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ir);
      union {
        int32_t real;
        uint32_t base;
      } u_broadband;
      u_broadband.real = this->broadband;
      *(outbuffer + offset + 0) = (u_broadband.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_broadband.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_broadband.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_broadband.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->broadband);
      union {
        float real;
        uint32_t base;
      } u_bmp_temp;
      u_bmp_temp.real = this->bmp_temp;
      *(outbuffer + offset + 0) = (u_bmp_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bmp_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bmp_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bmp_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bmp_temp);
      union {
        float real;
        uint32_t base;
      } u_bmp_pressure;
      u_bmp_pressure.real = this->bmp_pressure;
      *(outbuffer + offset + 0) = (u_bmp_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bmp_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bmp_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bmp_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bmp_pressure);
      union {
        float real;
        uint32_t base;
      } u_bmp_alt;
      u_bmp_alt.real = this->bmp_alt;
      *(outbuffer + offset + 0) = (u_bmp_alt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bmp_alt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bmp_alt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bmp_alt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bmp_alt);
      union {
        float real;
        uint32_t base;
      } u_dht_humidity;
      u_dht_humidity.real = this->dht_humidity;
      *(outbuffer + offset + 0) = (u_dht_humidity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dht_humidity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dht_humidity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dht_humidity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dht_humidity);
      union {
        float real;
        uint32_t base;
      } u_dht_temp;
      u_dht_temp.real = this->dht_temp;
      *(outbuffer + offset + 0) = (u_dht_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dht_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dht_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dht_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dht_temp);
      union {
        float real;
        uint32_t base;
      } u_ratio;
      u_ratio.real = this->ratio;
      *(outbuffer + offset + 0) = (u_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ratio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ratio);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_ir;
      u_ir.base = 0;
      u_ir.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ir.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ir.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ir.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ir = u_ir.real;
      offset += sizeof(this->ir);
      union {
        int32_t real;
        uint32_t base;
      } u_broadband;
      u_broadband.base = 0;
      u_broadband.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_broadband.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_broadband.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_broadband.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->broadband = u_broadband.real;
      offset += sizeof(this->broadband);
      union {
        float real;
        uint32_t base;
      } u_bmp_temp;
      u_bmp_temp.base = 0;
      u_bmp_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bmp_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bmp_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bmp_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bmp_temp = u_bmp_temp.real;
      offset += sizeof(this->bmp_temp);
      union {
        float real;
        uint32_t base;
      } u_bmp_pressure;
      u_bmp_pressure.base = 0;
      u_bmp_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bmp_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bmp_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bmp_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bmp_pressure = u_bmp_pressure.real;
      offset += sizeof(this->bmp_pressure);
      union {
        float real;
        uint32_t base;
      } u_bmp_alt;
      u_bmp_alt.base = 0;
      u_bmp_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bmp_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bmp_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bmp_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bmp_alt = u_bmp_alt.real;
      offset += sizeof(this->bmp_alt);
      union {
        float real;
        uint32_t base;
      } u_dht_humidity;
      u_dht_humidity.base = 0;
      u_dht_humidity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dht_humidity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dht_humidity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dht_humidity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dht_humidity = u_dht_humidity.real;
      offset += sizeof(this->dht_humidity);
      union {
        float real;
        uint32_t base;
      } u_dht_temp;
      u_dht_temp.base = 0;
      u_dht_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dht_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dht_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dht_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dht_temp = u_dht_temp.real;
      offset += sizeof(this->dht_temp);
      union {
        float real;
        uint32_t base;
      } u_ratio;
      u_ratio.base = 0;
      u_ratio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ratio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ratio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ratio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ratio = u_ratio.real;
      offset += sizeof(this->ratio);
     return offset;
    }

    const char * getType(){ return "science/sensor"; };
    const char * getMD5(){ return "1c3ffddcb0bc54f66a56aad3a991f30f"; };

  };

}
#endif
