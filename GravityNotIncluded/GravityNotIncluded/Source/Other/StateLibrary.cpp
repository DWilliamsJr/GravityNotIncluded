#include "Other/StateLibrary.h"


StateLibrary::StateLibrary()
{
	// Create all my states w/ their size.

	// add all the possible exit states to each state
}

State& StateLibrary::GetState(short index)
{
	return m_StateList[index];
}