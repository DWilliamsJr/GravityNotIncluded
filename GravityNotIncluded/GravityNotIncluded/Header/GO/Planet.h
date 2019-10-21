#pragma once
#include "PCH.h"

#include "GameObject.h"
#include "Entity.h"
#include "Cure.h"

extern const short MEMBERLISTSIZE;

class Planet: public GameObject
{
private:

	Entity** m_MemberList;
	
	Resources m_ResourcePool;

	Request* m_Request;
	Disease *m_Disease;


public:
	Cure* m_Cure;	// probably removed after player input included....

	Planet(AI* t_AI, PhysicsComp* t_physics, SoundComp* t_sound, GraphicsComp* t_graphics);
	Planet();
	~Planet();

	void addMember(Entity *t_Entity);
	bool CheckAvalibility();
	void removeMember(short t_index);
	Entity* getMember(short t_index);


	Resources& getResources();

	Request* getRequest();

	void GameObject::update();

	void setDisease(Disease* t_disease);

	Disease* getDisease();

	void setCure(Cure* t_Cure);

	Cure* getCure();

	void newRequest(Request *t_request);

	void deleteCureAndDisease();
	void DeleteRequest();
};