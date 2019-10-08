#pragma once 

#include "PCH.h"
#include "Componet.h"

class PhysicsComp : public Componet
{
private:
	float m_mass;

	//vec2d m_Velocity;

	HitBox m_HitBox;

public:
	~PhysicsComp();
	/*
	PhysicsComp();

	void CheckCollision(PhysicsComp *t_PC);

	void updateVel(/*vec2D &t_Vec);*/
	
};