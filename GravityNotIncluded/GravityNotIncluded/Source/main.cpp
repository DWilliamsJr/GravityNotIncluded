#include "PCH.h"

#include "GravityNotIncluded.h"
#include "Comp/AI/Disease_AI.h"

int main()
{	
	{
		GravityNotIncluded tempGame;
		tempGame.GameLoop();		
		
		/*Timer tempTimer(__FILE__, __LINE__);
		//ObjectPool TempPool(5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5);

		Entity *testEntity = TempPool.newEntity();
		testEntity->getAI()->updateAI();

		Disease *testDisease = TempPool.newDisease(1);
		testDisease->getAI()->updateAI();

		Cure *testCure = TempPool.newCure(1);
		testCure->getAI()->updateAI();

		Planet *testPlanet = TempPool.newPlanet();
		testPlanet->getAI()->updateAI();
		*/
		message::printMessages(0);
		system("pause");
	}

	delete [] Messages;
}