#include "PCH.h"
#include "GO/Disease.h"

Disease::Disease(short size, AI* t_AI)
{
	m_Graphics = nullptr;
	m_Sound = nullptr;
	m_Physics = nullptr;

	m_AI = t_AI;
	if (m_AI == nullptr)
	{
		message(_ERROR, "DISEASE CREATED WITHOUT AI", __FILE__, __LINE__);
	}
	else
	{
		message(_LOG, "CREATED NEW DISEASE", __FILE__, __LINE__);
		m_size = size;
		m_Sequence = new char[size];
		m_AI->setParent(this);
		generate();
	}

}

Disease::Disease() /*NEVER CREATE A DISEASE LIKE THIS*/
{
}

void Disease::Evolve()
{
	m_Sequence[(m_size - 1)] = 'a' + (std::rand() % 26);
}

short Disease::getSize()
{
	return m_size;
}

void Disease::Compare(Cure* t_Cure)
{
	for (int x = 0; x < m_size; x++)
	{
		if (t_Cure->getSequence()[x] != this->m_Sequence[x])
		{
			t_Cure->setSequence(x, NULL);
		}
	}
}

void Disease::update(){}

void Disease::generate()
{
	srand((unsigned)time(0));
	for (int x = 0; x < m_size; x++)
	{
		m_Sequence[x] = 'a' + (std::rand() % 26);;
	}
}

Disease::~Disease()
{
	if (m_Sequence != nullptr)
	{
		delete [] m_Sequence;
	}

}