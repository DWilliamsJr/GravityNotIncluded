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