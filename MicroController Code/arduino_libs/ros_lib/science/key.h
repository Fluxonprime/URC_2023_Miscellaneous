#ifndef _ROS_science_key_h
#define _ROS_science_key_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace science
{

  class key : public ros::Msg
  {
    public:
      typedef int8_t _key_type;
      _key_type key;

    key():
      key(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_key;
      u_key.real = this->key;
      *(outbuffer + offset + 0) = (u_key.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_key;
      u_key.base = 0;
      u_key.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key = u_key.real;
      offset += sizeof(this->key);
     return offset;
    }

    const char * getType(){ return "science/key"; };
    const char * getMD5(){ return "ff9551f31e498850d27cbf681e7ad637"; };

  };

}
#endif
