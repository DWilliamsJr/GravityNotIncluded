#include "PCH.h"
#include "GO/GameObject.h"

GraphicsComp* GameObject::getGraphics()
{
	return m_Graphics;
}

SoundComp* GameObject::getsound()
{
	return m_Sound;
}

PhysicsComp* GameObject::getPhysics()
{
	return m_Physics;
}

AI* GameObject::getAI()
{
	return m_AI;
}

Pos& GameObject::getPos()
{
	return m_Pos;
}

std::string GameObject::getID()
{
	return m_ID;
}

void GameObject::setID(std::string t_ID)
{
	m_ID = t_ID;;
}


void GameObject::setPoolInfo(short t_PoolIndex, short t_Index)
{
	PoolInformation.PoolIndex = t_PoolIndex;
	PoolInformation.Location = t_Index;
}

PoolIndexInformation GameObject::getPoolInfo()
{
	return PoolInformation;
}

State& GameObject::peekState()
{
	if (m_State.size() > 0)
	{
		return m_State.top();
	}
	std::cout << " IT BROKE" << std::endl;
}

State* GameObject::popState()
{
	State* temp = &m_State.top();
	m_State.pop();
	return temp;
}

void GameObject::pushState(State *T_State)
{
	m_State.push(*T_State);
}
GameObject::~GameObject()
{
	message(_LOG, "GAMEOBJECT DESTRUCTOR CALLED :)", __FILE__, __LINE__);
	if (m_Graphics != nullptr)
	{
		m_Graphics->~GraphicsComp();
	}
	if (m_Sound != nullptr)
	{
		m_Sound->~SoundComp(); 
	}
	if (m_Physics != nullptr)
	{
		m_Physics->~PhysicsComp();
	}
}