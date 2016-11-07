#include "Locations.h"
#include "AdorkablePig.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include <iostream>


int main()
{
  //create a miner
	AdorkablePig adorkablePig(ent_Adorkable_liwei);

  //simply run the miner through a few Update calls
  for (int i=0; i<30; ++i)
  { 
	adorkablePig.Update();

	Sleep(800);
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "\n" << GetNameOfEntity(adorkablePig.ID()) << ": " << "哈哈，小猪，老公的生活。。。";
  //wait for a keypress before exiting
  PressAnyKeyToContinue();

  return 0;
}