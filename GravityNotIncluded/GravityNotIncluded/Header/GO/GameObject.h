#pragma once

#include "PCH.h"

#include "Comp/GraphicsComp.h"
#include "Comp/PhysicsComp.h"
#include "Comp/SoundComp.h"

class GameObject
{
private:
	GraphicsComp* m_Graphics;
	SoundComp* m_Sound;
	PhysicsComp* m_Physics;
	Pos m_Pos;
	std::string m_ID;

public:
	GraphicsComp* getGraphics();
	SoundComp* getsound();
	PhysicsComp* getPhysics();
	Pos& getPos();
	std::string getID();
protected:

	virtual void update() = 0;
};