#include "PCH.h"

#include "GravityNotIncluded.h"
#include <thread>



void THREADONE(GravityNotIncluded *tempGame)
{
	tempGame->GameLoop();
}

void THREADTWO(GravityNotIncluded *tempGame)
{
	while (true)
	{
		tempGame->getInput();
	}
}

int main()
{
{
GravityNotIncluded tempGame;

	std::thread gameloop(THREADONE, &tempGame);
	std::thread userinput(THREADTWO, &tempGame);
	gameloop.join();

	message::printMessages(_TIMER);
	system("pause");
}


	delete [] Messages;
}