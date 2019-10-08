#pragma once

#include "PCH.h"

#include "Comp/GraphicsComp.h"
#include "Comp/PhysicsComp.h"
#include "Comp/SoundComp.h"
#include "Comp/AI/AI.h"

#include "Other/sm/State.h"

class GameObject
{

protected:
	GraphicsComp* m_Graphics;
	SoundComp* m_Sound;
	PhysicsComp* m_Physics;
	AI* m_AI;
	Pos m_Pos;
	std::string m_ID;
	std::stack<State> m_State;
	virtual void update() = 0;
	 ~GameObject();	

	PoolIndexInformation PoolInformation;


public:
	bool DirtyFlag;

	GraphicsComp* getGraphics();
	SoundComp* getsound();
	PhysicsComp* getPhysics();
	AI* getAI();
	Pos& getPos();
	std::string getID();
	void setID(std::string t_ID);

	void pushState(State *T_State);

	State& peekState();

	State* popState();

	void setPoolInfo(short t_PoolIndex, short t_Index);
	PoolIndexInformation getPoolInfo();



};