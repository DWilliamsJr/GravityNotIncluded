#include "GO/Disease.h"

Disease::Disease(short size)
{
	m_size = size;
	m_Sequence = new char[size];

	// GET CURE AI COMP
	// GET PHYSICS COMP
	// GET GRAPHICS COMP
	// GET SOUND COMP
}

Disease::Disease() {}

void Disease::Evolve()
{
	// CHANGE UP THE SEQUENCE
}

bool Disease::Compare(Cure* t_Cure)
{
	for (int x = 0; x < m_size; x++)
	{
		if (t_Cure->getSequence()[x] != this->m_Sequence[x])
		{
			t_Cure->getSequence()[x] = NULL;

			return false;
		}
	}
	return true;
}

void Disease::update()
{

}

void Disease::generate()
{
	//RANDOMLY GENERATE THE M_SEQUENCE
}