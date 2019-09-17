#include "PCH.h"
#include "GO/Planet.h"


Planet::Planet()
{
	//SET MASS

	// AI COMPONET
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

Resources& Planet::getResources()
{
	return m_ResourcePool;
}

Request* Planet::getRequest()
{
	return m_Request;
}

void Planet::update()
{
	// TO DO :)
}
