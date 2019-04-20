#pragma once

#include <memory>

#include "doorBellIntf.h"


class SecuritySystem
{
 private:
  std::shared_ptr<DoorBellIntf> doorbell_{nullptr};
  unsigned int numDoorbellRings_{0};

 public:
  SecuritySystem(std::shared_ptr<DoorBellIntf> newDoorBell)
      : doorbell_{newDoorBell}
  {
  }

  bool ringDoorbell()
  {
    bool retVal{false};

    if (doorbell_->ring())
    {
      numDoorbellRings_++;
      retVal = true;
    }

    return retVal;
  }

  unsigned int getNumberRings() { return numDoorbellRings_; }
};
