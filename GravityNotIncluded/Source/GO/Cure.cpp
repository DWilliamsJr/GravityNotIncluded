#include "PCH.h"
#include "GO/Cure.h"

Cure::Cure(short size)
{
	
	m_size = size;
	m_Sequence = new char[size];
	isReady = false;
	// GET CURE AI COMP
	// GET PHYSICS COMP
	// GET GRAPHICS COMP
	// GET SOUND COMP
}

Cure::Cure() {}

void Cure::Construct(short t_index, char t_Char)
{
	m_Sequence[t_index] = t_Char;
}

bool Cure::Status()
{
	return isReady;
}

char* Cure::getSequence()
{
	return m_Sequence;
}

void Cure::setIsReady()
{
	isReady = true;
}

void Cure::update()
{

}
