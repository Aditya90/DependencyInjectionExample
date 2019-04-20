
#pragma once

#include "doorBellIntf.h"

class ButtonDoorBell : public DoorBellIntf
{
 public:
  bool ring() override
  {
    cout << "ButtonDoorBell rang \n";
    return true;
  }
};