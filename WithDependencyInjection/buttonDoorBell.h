
#pragma once

#include "doorBellIntf.h"

/**
 * @brief A class representing a simple button based doorbell
 */
class ButtonDoorBell : public DoorBellIntf
{
 public:
  bool ring() override
  {
    std::cout << "ButtonDoorBell rang \n";
    return true;
  }
};