#include "PCH.h"
#include "Other/StateLibrary.h"

enum stateNum
{
	STABLE = 0, DISEASEOUTBREAK, EPIDEMIC, RESOURCELOW,
	STAGEONE, STAGETWO, STAGETHREE, CURED,
	INPROGRESS, COMPLETED,
	HEALTHY, SICK, DEAD, HUNGRY
};

StateLibrary::StateLibrary()
{
	index = 0;
	m_StateList = new State[14];
		//PLANET
	pushState(*(new State(2, nullptr, "PLANET_STABLE")));			//STABLE
	pushState(*(new State(1, nullptr, "PLANET_DISEASEOUTBREAK")));	//DISEASEOUTBREAK
	pushState(*(new State(0, nullptr, "PLANET_EPIDEMIC")));			//EPIDEMIC
	pushState(*(new State(0, nullptr, "PLANET_RESOURCELOW")));		//RESOURCELOW

		//DISEASE
	pushState(*(new State(2, nullptr, "DISEASE_STAGEONE")));		//STAGEONE
	pushState(*(new State(2, nullptr, "DISEASE_STAGETWO")));		//STAGETWO
	pushState(*(new State(1, nullptr, "DISEASE_STAGETHREE")));		//STAGETHREE
	pushState(*(new State(0, nullptr, "DISEASE_CURED")));			//CURED

		//CURE
	pushState(*(new State(1, nullptr, "CURE_INPROGRESS")));			//INPROGRESS
	pushState(*(new State(0, nullptr, "CURE_COMPLETED")));			//COMPLETED

		//ENTITY
	pushState(*(new State(2, nullptr, "ENTITY_HEALTHY")));			//HEALTHY
	pushState(*(new State(1, nullptr, "ENTITY_SICK")));				//SICK
	pushState(*(new State(0, nullptr, "ENTITY_DEAD")));				//DEAD
	pushState(*(new State(0, nullptr, "ENTITY_HUNGRY")));			//HUNGRY



	// add all the possible exit states to each state
	State temp[2];
	temp[0] = m_StateList[DISEASEOUTBREAK];
	temp[1] = m_StateList[RESOURCELOW];
	pushSubState(STABLE, temp);

	temp[0] = m_StateList[EPIDEMIC];
	pushSubState(DISEASEOUTBREAK, temp);

	temp[0] = m_StateList[STAGETWO];
	temp[1] = m_StateList[CURED];
	pushSubState(STAGEONE, temp);

	temp[0] = m_StateList[STAGETHREE];
	temp[1] = m_StateList[CURED];
	pushSubState(STAGETWO, temp);

	temp[0] = m_StateList[CURED];
	pushSubState(STAGETHREE, temp);

	temp[0] = m_StateList[COMPLETED];
	pushSubState(INPROGRESS, temp);

	temp[0] = m_StateList[SICK];
	temp[1] = m_StateList[HUNGRY];
	pushSubState(HEALTHY, temp);

	temp[0] = m_StateList[DEAD];
	pushSubState(SICK, temp);
}

void StateLibrary::pushState(State& t_state)
{
	m_StateList[index] = t_state;
	index++;
	new message(_LOG, "Created New State: " + t_state.getID(), __FILE__, __LINE__);
}

void StateLibrary::pushSubState(int t_index, State t_StateList[])
{
	m_StateList[t_index].addStates(t_StateList);
	new message(_LOG, "Pushed Substates to: " + m_StateList[t_index].getID(), __FILE__, __LINE__);
}

State& StateLibrary::GetState(short index)
{
	return m_StateList[index];
}