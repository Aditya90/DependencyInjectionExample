#pragma once

#include <memory>

#include "doorBellIntf.h"

/**
 * @brief A class representing the security system. It is composed of multiple
 * objects.
 */
class SecuritySystem
{
 private:
  std::shared_ptr<DoorBellIntf> doorbell_{nullptr};
  unsigned int numDoorbellRings_{0};

 public:
  explicit SecuritySystem(std::shared_ptr<DoorBellIntf> newDoorBell)
      : doorbell_{newDoorBell}
  {
  }

  /**
   * @brief Ring the doorbell of the security system
   * @return Returns true if the doorbell rang, and false otherwise
   */
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

  /**
   * @brief Get the number of times the door bell in the security system rang
   * @return Number of times the doorbell rang
   */
  unsigned int getNumberRings() { return numDoorbellRings_; }
};
