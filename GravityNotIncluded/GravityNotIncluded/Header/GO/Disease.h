#include "PCH.h"
#pragma once

#include "GO/GameObject.h"
#include "Cure.h"

class Disease: public GameObject
{
private:
	char* m_Sequence;
	short m_size;

	void generate();

public:
	Disease(short size, AI* t_AI);
	~Disease();
	Disease();

	void Evolve();

	short getSize();
		// return -1 if cure is ready, how far off the incorrect character was.
	void Compare(Cure* t_Cure);

	void GameObject::update();
};