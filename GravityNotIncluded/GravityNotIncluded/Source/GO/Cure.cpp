#include "PCH.h"
#include "GO/Cure.h"

Cure::Cure(short size, AI *t_cure)
{
	m_Graphics = nullptr;
	m_Sound = nullptr;
	m_Physics = nullptr;

	if (t_cure != nullptr)
	{
	m_size = size;
	m_Sequence = new char[size]();

	m_AI = t_cure;
	m_AI->setParent(this);
	message(_LOG, "NEW CURE CREATED", __FILE__, __LINE__);
	}
	else
	{
		message(_ERROR, "CURE CREATED WITHOUT A AI", __FILE__, __LINE__);
	}
	
}

Cure::Cure() {/* NEVER ACTUALLY CREATE A CURE LIKE THIS*/}

void Cure::Construct(short t_index, char t_Char)
{
	m_Sequence[t_index] = t_Char;
}

char* Cure::getSequence()
{
	return m_Sequence;
}

void Cure::setSequence(int x, char temp)
{
	m_Sequence[x] = temp;
}

void Cure::update()
{

}

Cure::~Cure()
{
	delete[] m_Sequence;
}