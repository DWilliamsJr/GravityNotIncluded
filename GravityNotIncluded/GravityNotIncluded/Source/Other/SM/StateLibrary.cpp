#include "PCH.h"
#include "Other/SM/StateLibrary.h"



StateLibrary::StateLibrary()
{
}

void StateLibrary::init()
{
	m_index = 0;
	m_StateList = new State[HUNGRY + 1];
		//PLANET
	pushState(StateIDList[STABLE]);
	pushState(StateIDList[DISEASEOUTBREAK]);
	pushState(StateIDList[EPIDEMIC]);
	pushState(StateIDList[RESOURCELOW]);

		//DISEASE
	pushState(StateIDList[STAGEONE]);	
	pushState(StateIDList[STAGETWO]);		
	pushState(StateIDList[STAGETHREE]);		
	pushState(StateIDList[CURED]);		

		//CURE
	pushState(StateIDList[INPROGRESS]);	
	pushState(StateIDList[COMPLETED]);	

		//ENTITY
	pushState(StateIDList[HEALTHY]);	
	pushState(StateIDList[SICK]);	
	pushState(StateIDList[DEAD]);		
	pushState(StateIDList[HUNGRY]);		

}
void StateLibrary::pushState(std::string temp)
{
	if (m_index < HUNGRY + 1)
	{
		m_StateList[m_index].setID(temp);
		message(_LOG, "Created New State: " + m_StateList[m_index].getID(), __FILE__, __LINE__);
		m_index++;
	}
	else
	{
		message(_ERROR, "FAILED TO CREATE STATE: " + temp, __FILE__, __LINE__);
	}
	
}

State& StateLibrary::GetState(short t_index)
{
	return m_StateList[t_index];
}
StateLibrary::~StateLibrary()
{
	delete [] m_StateList;
}