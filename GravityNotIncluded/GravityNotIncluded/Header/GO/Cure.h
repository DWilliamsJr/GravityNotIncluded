#pragma once

#include "PCH.h"
#include "GO/GameObject.h"

class Cure : public GameObject
{
private:
	char* m_Sequence;
	short m_size;

	bool isReady;

	//Cure_AI* m_AI;


public:
	Cure(short size);

	Cure();

	void Construct(short t_index, char t_Char);

	char* getSequence();

	void setIsReady();

	bool Status();

	void GameObject::update();
};
