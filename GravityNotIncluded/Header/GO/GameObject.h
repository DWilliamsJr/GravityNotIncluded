#pragma once

#include "PCH.h"

#include "Comp/GraphicsComp.h"
#include "Comp/PhysicsComp.h"
#include "Comp/SoundComp.h"
#include "Comp/AI/AI.h"

#include "Other/Resources.h"
							#include "Other/Request.h"
#include "Other/State.h"

class GameObject
{

public:
	GraphicsComp* getGraphics();
	SoundComp* getsound();
	PhysicsComp* getPhysics();
	Pos& getPos();
	std::string getID();
	void setID(std::string t_ID);

protected:
	GraphicsComp* m_Graphics;
	SoundComp* m_Sound;
	PhysicsComp* m_Physics;
	Pos m_Pos;
	std::string m_ID;
	virtual void update() = 0;
};