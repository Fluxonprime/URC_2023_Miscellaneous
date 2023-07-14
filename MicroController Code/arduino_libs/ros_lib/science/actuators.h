#ifndef _ROS_science_actuators_h
#define _ROS_science_actuators_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace science
{

  class actuators : public ros::Msg
  {
    public:
      typedef int16_t _stepper_type;
      _stepper_type stepper;

    actuators():
      stepper(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_stepper;
      u_stepper.real = this->stepper;
      *(outbuffer + offset + 0) = (u_stepper.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stepper.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->stepper);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_stepper;
      u_stepper.base = 0;
      u_stepper.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stepper.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stepper = u_stepper.real;
      offset += sizeof(this->stepper);
     return offset;
    }

    const char * getType(){ return "science/actuators"; };
    const char * getMD5(){ return "152c8c10bece151f1577bbe54163d019"; };

  };

}
#endif
