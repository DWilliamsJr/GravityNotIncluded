#include "PCH.h"
#include "Other/StateLibrary.h"



StateLibrary::StateLibrary()
{

}

void StateLibrary::init()
{
	m_index = 0;
	m_StateList = new State[14];
	//PLANET
	pushState(*(new State(2, nullptr, StateIDList[STABLE])));		//STABLE
	pushState(*(new State(1, nullptr, StateIDList[DISEASEOUTBREAK])));	//DISEASEOUTBREAK
	pushState(*(new State(0, nullptr, StateIDList[EPIDEMIC])));			//EPIDEMIC
	pushState(*(new State(0, nullptr, StateIDList[RESOURCELOW])));		//RESOURCELOW

		//DISEASE
	pushState(*(new State(2, nullptr, StateIDList[STAGEONE])));			//STAGEONE
	pushState(*(new State(2, nullptr, StateIDList[STAGETWO])));			//STAGETWO
	pushState(*(new State(1, nullptr, StateIDList[STAGETHREE])));		//STAGETHREE
	pushState(*(new State(0, nullptr, StateIDList[CURED])));			//CURED

		//CURE
	pushState(*(new State(1, nullptr, StateIDList[INPROGRESS])));		//INPROGRESS
	pushState(*(new State(0, nullptr, StateIDList[COMPLETED])));		//COMPLETED

		//ENTITY
	pushState(*(new State(2, nullptr, StateIDList[HEALTHY])));			//HEALTHY
	pushState(*(new State(1, nullptr, StateIDList[SICK])));				//SICK
	pushState(*(new State(0, nullptr, StateIDList[DEAD])));				//DEAD
	pushState(*(new State(0, nullptr, StateIDList[HUNGRY])));			//HUNGRY



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
	m_StateList[m_index] = t_state;
	m_index++;
	new message(_LOG, "Created New State: " + t_state.getID(), __FILE__, __LINE__);
}

void StateLibrary::pushSubState(int t_index, State t_StateList[])
{
	m_StateList[t_index].addStates(t_StateList);
	new message(_LOG, "Pushed Substates to: " + m_StateList[t_index].getID(), __FILE__, __LINE__);
}

State& StateLibrary::GetState(short t_index)
{
	return m_StateList[t_index];
}