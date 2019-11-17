#include "PCH.h"
#include "Comp/AI/Disease_AI.h"

extern StateLibrary *StaticStateLibrary;

Disease_AI::Disease_AI()
{

	message(_LOG, "CREATED NEW DISEASE_AI", __FILE__, __LINE__);
}


void Disease_AI::updateAI()
{
	if ((ParentDisease->peekState().getID()).compare(StateIDList[STAGEONE]) == 0)
	{
		message(_LOG, "Disease new state " + StateIDList[STAGETWO], __FILE__, __LINE__);

		ParentDisease->pushState(&StaticStateLibrary->GetState(STAGETWO));
	}
	else if ((ParentDisease->peekState().getID()).compare(StateIDList[STAGETWO]) == 0)
	{
		message(_LOG, "Disease new state "  + StateIDList[STAGETHREE], __FILE__, __LINE__);

		ParentDisease->pushState(&StaticStateLibrary->GetState(STAGETHREE));
		ParentDisease->Evolve();
	}
	else if ((ParentDisease->peekState().getID()).compare(StateIDList[STAGETHREE]) == 0)
	{
		ParentDisease->Evolve();
	}
}
	

Disease* Disease_AI::getParent()
{
	return ParentDisease;
}

void Disease_AI::setParent(void* t_parent)
{
	ParentDisease = (Disease*)t_parent;
	ParentDisease->pushState(&StaticStateLibrary->GetState(STAGEONE));
}