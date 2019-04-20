#include <cassert>
#include <iostream>

#include "../securitySystem.h"

/**
 * After default construction, ring the doorbell and check the the return value
 * and ensure it is false
 */
void GivenDefaultConstWhenRingDoorbellThenReturnTrue()
{
  SecuritySystem secSystem;
  assert(secSystem.ringDoorbell() == true);

  std::cout << "GivenDefaultConstWhenRingDoorbellThenReturnTrue - Passed \n";
}

/**
 * After default construction, ring the doorbell a couple of times and ensure
 * the number of rings is correct.
 */
void GivenDefaultConstWhenRingDoorbellTwiceThenNumberOfRings2()
{
  unsigned int expectedNumberOfRings{2};

  SecuritySystem secSystem;

  secSystem.ringDoorbell();
  secSystem.ringDoorbell();

  assert(secSystem.getNumberRings() == expectedNumberOfRings);

  std::cout
      << "GivenDefaultConstWhenRingDoorbellTwiceThenNumberOfRings2 - Passed \n";
}

int main()
{
  GivenDefaultConstWhenRingDoorbellThenReturnTrue();
  GivenDefaultConstWhenRingDoorbellTwiceThenNumberOfRings2();

  // Unable to test the following
  // 1. Set the return value of ringDoorbell() to false
  // 2. Unable to disable ringing doorbell to see if that affects
  // getNumberRings()

  return 0;
}
