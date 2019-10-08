#pragma once

#include "PCH.h"
#include "Other/SM/State.h"

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

class StateLibrary// AT THIS POINT WHAT'S THE POINT OF HAVING A STATE OBJECT?????
{
private:
	State* m_StateList;
	short m_index;

	void pushState(std::string temp);

public:
	StateLibrary();
	~StateLibrary();
	void init();

	State& GetState(short t_index);

};