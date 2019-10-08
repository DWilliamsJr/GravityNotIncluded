#pragma once

#include "PCH.h"
#include "GameObject.h"
#include "Disease.h"


class Entity: public GameObject
{
private:
	Resources m_ResContribution;
	Resources m_ResConsumption;

	Disease* m_Disease;

public:
	Entity(AI* t_AI);

	Entity();
	~Entity();

	void GameObject::update();

	Disease* getDisease();

	void setDisease(Disease* t_disease);

	Resources& getResContribution();

	Resources& getResConsumption();
};