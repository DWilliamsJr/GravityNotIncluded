#include "PCH.h"
#include "Comp/AI/Planet_AI.h"

#include "Other/StateLibrary.h"

extern StateLibrary *StaticStateLibrary;

Planet_AI::Planet_AI()
{
	new message(_LOG, "CREATED NEW Planet_AI", __FILE__, __LINE__);
}

void Planet_AI::update()
{
	int temp[5] = { 0, 0, 0, 0, 0 };
	Entity tempMember;
	for (int x = 0; x < ParentPlanet->memberListSize(); x++)
	{
		tempMember = *ParentPlanet->getMember(x);
		temp[0] = tempMember.getResContribution().Food;
		temp[1] = tempMember.getResContribution().Water;
		temp[2] = tempMember.getResContribution().Medicine;
		temp[3] = tempMember.getResContribution().Wood;
		temp[4] = tempMember.getResContribution().Tech;

		temp[0] -= tempMember.getResConsumption().Food;
		temp[1] -= tempMember.getResConsumption().Water;
		temp[2] -= tempMember.getResConsumption().Medicine;
		temp[3] -= tempMember.getResConsumption().Wood;
		temp[4] -= tempMember.getResConsumption().Tech;
		ParentPlanet->getResources().setResources(temp[0], temp[1], temp[4], temp[3], temp[2]);

		if (tempMember.getDisease() != nullptr && ParentPlanet->getDisease() == nullptr)
		{
			ParentPlanet->pushState(&StaticStateLibrary->GetState(DISEASEOUTBREAK));
			ParentPlanet->setDisease(tempMember.getDisease());
		}
		else if (tempMember.getDisease() == nullptr && ParentPlanet->getDisease() != nullptr)
		{
			ParentPlanet->getMember(x)->setDisease(*ParentPlanet->getDisease());
		}
		else if (tempMember.getDisease() != nullptr && ParentPlanet->getDisease() != nullptr && distribution(generator) == 4)
		{
			ParentPlanet->getMember(x)->setDeathFlag();
		}

	}

	State tempState = *ParentPlanet->peekState();

	if (tempState.getID().compare(StateIDList[STABLE]))
	{
		if (ParentPlanet->getResources().Food < 100		|| 
			ParentPlanet->getResources().Water < 100	||
			ParentPlanet->getResources().Medicine < 100 ||
			ParentPlanet->getResources().Wood < 100		||
			ParentPlanet->getResources().Tech < 100		);
		{
			ParentPlanet->pushState(&StaticStateLibrary->GetState(RESOURCELOW));
		}
	}
	else if (tempState.getID().compare(StateIDList[DISEASEOUTBREAK]) && ParentPlanet->getRequest() != nullptr && distribution(generator) == 4)
	{
			// THIS REQUEST SHOULD BE CREATED VIA THE OBJECT POOL
			Request *temp = new Request();
				// PASS THE DISEASE
			ParentPlanet->newRequest(temp);
	}
	else if (tempState.getID().compare(StateIDList[EPIDEMIC]) && ParentPlanet->getRequest() != nullptr)
	{
			// THIS REQUEST SHOULD BE CREATED VIA THE OBJECT POOL
			Request *temp = new Request();
				// PASS THE DISEASE
			ParentPlanet->newRequest(temp);
	}
	else if (tempState.getID().compare(StateIDList[RESOURCELOW]) && ParentPlanet->getRequest() != nullptr)
	{
			// THIS REQUEST SHOULD BE CREATED VIA THE OBJECT POOL
			Request *temp = new Request();
			temp->M_resources.Food = 100;
			temp->M_resources.Water = 100;
			temp->M_resources.Wood = 100;
			temp->M_resources.Tech = 100;
			temp->M_resources.Medicine = 100;
			ParentPlanet->newRequest(temp);
	}

	// IF RESOURCE REQUEST == FULFILLED 
		// POP STATE

}

Planet* Planet_AI::getParent()
{
	return ParentPlanet;
}

void Planet_AI::setParent(Planet& t_parent)
{
	ParentPlanet = &t_parent;
}
