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