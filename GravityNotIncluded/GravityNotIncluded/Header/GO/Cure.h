#include "PCH.h"
#pragma once

#include "GO/GameObject.h"

class Cure : public GameObject
{
private:
	char* m_Sequence;
	short m_size;

public:
	Cure(short size, AI *t_cure);
	~Cure();
	Cure();

	void Construct(short t_index, char t_Char);

	char* getSequence();
	void setSequence(int x, char temp);

	void GameObject::update();
};
