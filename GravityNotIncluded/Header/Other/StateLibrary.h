#pragma once

#include "PCH.h"
#include "Other/State.h"

enum stateNum
{
	STABLE = 0, DISEASEOUTBREAK, EPIDEMIC, RESOURCELOW,
	STAGEONE, STAGETWO, STAGETHREE, CURED,
	INPROGRESS, COMPLETED,
	HEALTHY, SICK, DEAD, HUNGRY
};

static const std::string StateIDList[14] =
{ "PLANET_STABLE", "PLANET_DISEASEOUTBREAK", "PLANET_EPIDEMIC", "PLANET_RESOURCELOW"
, "DISEASE_STAGEONE", "DISEASE_STAGETWO", "DISEASE_STAGETHREE", "DISEASE_CURED"
, "CURE_INPROGRESS", "CURE_COMPLETED"
, "ENTITY_HEALTHY", "ENTITY_SICK", "ENTITY_DEAD", "ENTITY_HUNGRY" };

class StateLibrary
{
private:
	State* m_StateList;
	short m_index;

	void pushState(State& t_state);
	void pushSubState(int t_index, State t_StateList[]);

public:
	StateLibrary();
	void init();

	State& GetState(short t_index);

};