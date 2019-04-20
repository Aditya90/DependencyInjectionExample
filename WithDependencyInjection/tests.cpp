#include <cassert>
#include <iostream>

#include "doorBellIntf.h"
#include "securitySystem.h"

class TestDoorBell : public DoorBellIntf
{
 private:
  bool ringRetVal_{false};

 public:
  bool ring() override { return ringRetVal_; }

  void setRingRetVal(bool newRetVal) { ringRetVal_ = newRetVal; }
};

void GivenTestBellDefaultWhenRingDoorbellThenReturnFalse()
{
  auto testbell = std::make_shared<TestDoorBell>();
  SecuritySystem secSystem(testbell);
  assert(secSystem.ringDoorbell() == false);

  std::cout
      << "GivenTestBellDefaultWhenRingDoorbellThenReturnFalse - Passed \n";
}

void GivenTestBellTrueWhenRingDoorbellThenReturnTrue()
{
  auto testbell = std::make_shared<TestDoorBell>();
  SecuritySystem secSystem(testbell);

  testbell->setRingRetVal(true);
  assert(secSystem.ringDoorbell() == true);

  std::cout << "GivenTestBellTrueWhenRingDoorbellThenReturnTrue - Passed \n";
}

void GivenTestBellComboWhenRingDoorbellThenReturnCorrectRings()
{
  unsigned int expectedNumberOfRings{0};

  auto testbell = std::make_shared<TestDoorBell>();
  SecuritySystem secSystem(testbell);

  secSystem.ringDoorbell();

  secSystem.ringDoorbell();

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
