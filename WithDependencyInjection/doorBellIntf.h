#pragma once

/**
 * @brief Abtract base class for anything which wishes to implement
 * the APIs expect out of doorbells
 */
class DoorBellIntf
{
 public:
  /**
   * @brief Ring the doorbell once
   */
  virtual bool ring() = 0;
};