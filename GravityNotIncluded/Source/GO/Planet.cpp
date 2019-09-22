#include "PCH.h"
#include "GO/Planet.h"


Planet::Planet()
{
	new message(_LOG, "CREATED NEW PLANET", __FILE__, __LINE__);
	//SET MASS

	// get ai comp and set it's parent == this

	// PHYSICS COMPONET
	// GRAPHICS COMPONET
	// SOUND COMPONET
}

void Planet::addMember(Entity *t_Entity)
{
	m_MemberList.push_back(*t_Entity);
}

void Planet::pushState(State *T_State)
{
	m_State.push(*T_State);
}

State* Planet::peekState()
{
	return &m_State.top();
}

State* Planet::popState()
{
	State *temp = &m_State.top();
	m_State.pop();
	return temp;
}

Entity* Planet::getMember(short index)
{

	return &m_MemberList.at(index);
}
void Planet::removeMember(short index)
{
	// ERASES THE ELEMENT AT (INDEX+1)
	m_MemberList.erase(m_MemberList.begin() + index);
}


Resources& Planet::getResources()
{
	return m_ResourcePool;
}

Request* Planet::getRequest()
{
	return m_Request;
}

int Planet::memberListSize()
{
	return m_MemberList.size();
}

void Planet::newRequest(Request *t_request)
{
	m_Request = t_request;
}

void  Planet::setDisease(Disease* t_disease)
{
	m_Disease = t_disease;
}

Disease*  Planet::getDisease()
{
	return m_Disease;
}

void Planet::useCure(Cure* t_cure)
{
	if (t_cure->Status() == false)
	{
		new message(_ERROR, "Premature Cure : " + t_cure->getID() + "sent to planet :" + getID(), __FILE__, __LINE__);
		return;
	}

	for (int x = 0; x < m_MemberList.size(); x++)
	{
		m_MemberList.at(x).cure();
	}
	m_Disease = nullptr;
}


void Planet::update()
{
	// TO DO :)
}