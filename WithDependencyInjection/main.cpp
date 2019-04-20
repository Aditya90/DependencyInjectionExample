#include <iostream>
#include <memory>

#include "buttonDoorBell.h"
#include "videoDoorBell.h"
#include "securitySystem.h"

using namespace std;

int main()   
{
  // Create a security system with a button doorbell
  auto newButtonDoorBell = std::make_shared<ButtonDoorBell>();
  SecuritySystem secSystemWithButtonDoorbell(newButtonDoorBell);
  secSystemWithButtonDoorbell.ringDoorbell();

  // Create a security system with a video doorbell  
  auto newVideoDoorBell = std::make_shared<VideoDoorBell>();
  SecuritySystem secSystemWithVideoDoorbell(newVideoDoorBell);
  secSystemWithVideoDoorbell.ringDoorbell();
  
  return 0;
}
