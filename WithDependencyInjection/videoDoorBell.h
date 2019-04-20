
#pragma once

#include "doorBellIntf.h"

class VideoDoorBell : public DoorBellIntf
{
 public:
  bool ring() override
  {
    cout << "VideoDoorBell rang \n";
    return true;
  }
};