#include <cassert>
#include <iostream>

#include "../doorBellIntf.h"
#include "../securitySystem.h"

/**
 * @brief A test doorbell class which allows us to manipulate
 * the doorbell to facilitate easy testing.
 */
class TestDoorBell : public DoorBellIntf
{
 private:
  bool ringRetVal_{false};

 public:
  bool ring() override { return ringRetVal_; }

  /**
   * @brief Test function which allows us to specify whether the ring() API
   * returns true or false
   * @param newRetVal Return value of the ring API
   */
  void setRingRetVal(bool newRetVal) { ringRetVal_ = newRetVal; }
};

/**
 * After construction with a test door bell, ring the doorbell and check the
 * return value and ensure it is false
 */
void GivenTestBellDefaultWhenRingDoorbellThenReturnFalse()
{
  auto testbell = std::make_shared<TestDoorBell>();
  SecuritySystem secSystem(testbell);
  assert(secSystem.ringDoorbell() == false);

  std::cout
      << "GivenTestBellDefaultWhenRingDoorbellThenReturnFalse - Passed \n";
}

/**
 * Set the test door bell to return true, ring the doorbell and check the
 * return value and ensure it is true
 */
void GivenTestBellTrueWhenRingDoorbellThenReturnTrue()
{
  auto testbell = std::make_shared<TestDoorBell>();
  SecuritySystem secSystem(testbell);

  testbell->setRingRetVal(true);
  assert(secSystem.ringDoorbell() == true);

  std::cout << "GivenTestBellTrueWhenRingDoorbellThenReturnTrue - Passed \n";
}

/**
 * Ring the bell with a default test bell, then set the test door bell to return
 * true. Make sure that the getNumberRings returns a number only for calls to
 * the ringDoorbell() when the return value was set to true.
 */
void GivenTestBellComboWhenRingDoorbellThenReturnCorrectRings()
{
  unsigned int expectedNumberOfRings{0};

  auto testbell = std::make_shared<TestDoorBell>();
  SecuritySystem secSystem(testbell);

  // As the default value is false, the 2 times we ring here it does not
  // increment the ring count.
  secSystem.ringDoorbell();
  secSystem.ringDoorbell();

  // We now set the ring return value to be true through our test API
  // and this will cause the next ring to increment the ring count.
  testbell->setRingRetVal(true);
  secSystem.ringDoorbell();
  expectedNumberOfRings++;

  assert(secSystem.getNumberRings() == expectedNumberOfRings);

  std::cout
      << "GivenTestBellComboWhenRingDoorbellThenReturnCorrectRings - Passed \n";
}

int main()
{
  GivenTestBellDefaultWhenRingDoorbellThenReturnFalse();
  GivenTestBellTrueWhenRingDoorbellThenReturnTrue();
  GivenTestBellComboWhenRingDoorbellThenReturnCorrectRings();

  return 0;
}
