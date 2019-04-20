#include <iostream>
#include <memory>

#include "securitySystem.h"

using namespace std;

int main()
{
  // Create a security system and ring the doorbell
  SecuritySystem secSystem;
  secSystem.ringDoorbell();
  cout << "Number of door bell rings : " << secSystem.getNumberRings();
  return 0;
}
