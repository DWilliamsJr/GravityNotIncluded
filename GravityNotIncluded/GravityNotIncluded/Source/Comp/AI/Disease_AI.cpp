#include "PCH.h"
#include "Comp/AI/Disease_AI.h"

extern StateLibrary *StaticStateLibrary;

Disease_AI::Disease_AI()
{

	message(_LOG, "CREATED NEW DISEASE_AI", __FILE__, __LINE__);
	StartTime = std::clock();
	Elapsed = 0;
}


void Disease_AI::updateAI()
{
	/*
		Elapsed = (std::clock() - StartTime) / (double)CLOCKS_PER_SEC;
		if (Elapsed > .005)
		{
			std::ostringstream SS;
			SS << Elapsed;
			if ((ParentDisease->peekState().getID()).compare(StateIDList[STAGEONE]) == 0)
			{
				message(_TestGame, "Disease new state: Elapsed Time: " + SS.str() + " " + StateIDList[STAGETWO], __FILE__, __LINE__);

				ParentDisease->pushState(&StaticStateLibrary->GetState(STAGETWO));
			}
			else if ((ParentDisease->peekState().getID()).compare(StateIDList[STAGETWO]) == 0)
			{
				message(_TestGame, "Disease new state: Elapsed Time: " + SS.str() + " " + StateIDList[STAGETHREE], __FILE__, __LINE__);

				ParentDisease->pushState(&StaticStateLibrary->GetState(STAGETHREE));
				//ParentDisease->Evolve();
			}
			else if ((ParentDisease->peekState().getID()).compare(StateIDList[STAGETHREE]) == 0)
			{
				ParentDisease->Evolve();
			}
			Elapsed = 0;
		}
		*/
	
}

Disease* Disease_AI::getParent()
{
	return ParentDisease;
}

void Disease_AI::setParent(void* t_parent)
{
	ParentDisease = (Disease*)t_parent;
	ParentDisease->pushState(&StaticStateLibrary->GetState(STAGEONE));
	std::cout << ParentDisease->peekState().getID() << std::endl;
}