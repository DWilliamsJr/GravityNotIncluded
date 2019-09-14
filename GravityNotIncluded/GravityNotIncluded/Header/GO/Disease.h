#pragma once

#include "PCH.h"
#include "GO/GameObject.h"
#include "Cure.h"

class Disease: public GameObject
{
private:
	const char* m_Sequence;
	short m_size;

	//Disease_AI* m_AI;

	void generate();

public:
	Disease(short size);

	Disease();

	void Evolve();

	bool Compare(Cure* t_Cure);

	void GameObject::update();
};