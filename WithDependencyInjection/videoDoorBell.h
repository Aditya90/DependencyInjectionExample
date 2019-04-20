
#pragma once

#include "doorBellIntf.h"

/**
 * @brief A class representing a video based doorbell
 */
class VideoDoorBell : public DoorBellIntf
{
 public:
  bool ring() override
  {
    std::cout << "VideoDoorBell rang \n";
    return true;
  }
};