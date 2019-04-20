#include <iostream>
#include <memory>

#include "buttonDoorBell.h"
#include "securitySystem.h"
#include "videoDoorBell.h"

using namespace std;

int main()
{
  // Create a security system with a button doorbell
  auto newButtonDoorBell = std::make_shared<ButtonDoorBell>();
  SecuritySystem secSystemWithButtonDoorbell(newButtonDoorBell);
  secSystemWithButtonDoorbell.ringDoorbell();
  cout << "Number of door bell rings : "
       << secSystemWithButtonDoorbell.getNumberRings() << std::endl;

  // Create a security system with a video doorbell
  auto newVideoDoorBell = std::make_shared<VideoDoorBell>();
  SecuritySystem secSystemWithVideoDoorbell(newVideoDoorBell);
  secSystemWithVideoDoorbell.ringDoorbell();
  cout << "Number of door bell rings : "
       << secSystemWithVideoDoorbell.getNumberRings() << std::endl;

  return 0;
}
