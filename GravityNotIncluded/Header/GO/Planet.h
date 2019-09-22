#pragma once
#include "PCH.h"

#include "Other/Resources.h"
#include "Other/Request.h"
#include "Other/State.h"

#include "GameObject.h"
#include "Entity.h"
#include "Cure.h"

class Planet: public GameObject
{
private:
	std::vector<Entity> m_MemberList;
	Resources m_ResourcePool;
	Request* m_Request;
	std::stack<State> m_State;
	Disease *m_Disease;
	AI* m_AI;

public:
	Planet();

	void addMember(Entity *t_Entity);

	void removeMember(short index);

	void pushState(State *T_State);

	void setDisease(Disease* t_disease);

	Disease* getDisease();

	State* peekState();

	State* popState();

	Entity* getMember(short index);

	Resources& getResources();

	Request* getRequest();

	void newRequest(Request *t_request);

	void GameObject::update();

	int memberListSize();

	void useCure(Cure* t_cure);

};