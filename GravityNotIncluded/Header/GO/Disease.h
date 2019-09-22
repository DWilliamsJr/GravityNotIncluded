#include "PCH.h"
#pragma once

#include "GO/GameObject.h"
#include "Cure.h"

class Disease: public GameObject
{
private:
	const char* m_Sequence;
	short m_size;
	// chance to kill

	//Disease_AI* m_AI;

	void generate();

public:
	Disease(short size);

	Disease();

	void Evolve();

	short getSize();

	bool Compare(Cure* t_Cure);

	void GameObject::update();
};