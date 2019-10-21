#include "PCH.h"
#include "GO/Planet.h"


Planet::Planet(AI* t_AI, PhysicsComp* t_physics, SoundComp* t_sound, GraphicsComp* t_graphics)
{
	m_AI = t_AI;
	m_Physics = t_physics;
	m_Graphics = t_graphics;
	m_Sound = t_sound;
	
	if (m_AI == nullptr)
	{
		 message(_ERROR, "PLANET CREATED WITHOUT AI", __FILE__, __LINE__);
	}
	else
	{
		m_Request = nullptr;
		m_Disease = nullptr;
		m_Cure = nullptr;

		m_ResourcePool.Food = 1000;
		m_ResourcePool.Water = 1000;
		m_ResourcePool.Medicine = 1000;
		m_ResourcePool.Tech = 1000;
		m_ResourcePool.Wood = 1000;

		m_MemberList = new Entity*[MEMBERLISTSIZE]();
		std::fill_n(m_MemberList, MEMBERLISTSIZE, nullptr);

		m_AI->setParent(this);
		message(_LOG, "SET PARENTPALNET", __FILE__, __LINE__);
		message(_LOG, "CREATED NEW PLANET", __FILE__, __LINE__);
	}

	

}
Planet::Planet() {}
void Planet::addMember(Entity *t_Entity)
{
	for(int x = 0; x < MEMBERLISTSIZE; x++)
	{
		if (m_MemberList[x] == nullptr)
		{
		m_MemberList[x] = (t_Entity);
		return;
		}
	}
}

bool Planet::CheckAvalibility()
{
	for (int x = 0; x < MEMBERLISTSIZE; x++)
	{
		if (m_MemberList[x] == nullptr)
		{
			return true;
		}
	}
	getAI()->updateMessage = "MEMBER LIST IS FULL";
	return false;
}

Entity* Planet::getMember(short t_index)
{
	if (t_index >= MEMBERLISTSIZE)
	{
		return nullptr;
	}
	return m_MemberList[t_index];
}
void Planet::removeMember(short t_index)
{
	m_MemberList[t_index] = nullptr;
}


Resources& Planet::getResources()
{
	return m_ResourcePool;
}

Request* Planet::getRequest()
{
	return m_Request;
}

void Planet::newRequest(Request *t_request)
{
	
		if (m_Request != nullptr)
		{
			message(_ERROR, "PLANET_REQUEST ALREADY EXIST", __FILE__, __LINE__);
			return;
		}
		m_Request = t_request;
}

void  Planet::setDisease(Disease* t_disease)
{
	
		if (m_Disease != nullptr)
		{
			message(_ERROR, "Planet_DISEASE ALREADY EXIST", __FILE__, __LINE__);
			return;
		}
		m_Disease = t_disease;
}

Disease*  Planet::getDisease()
{
		if (m_Disease != nullptr)
		{
			return m_Disease;
		}
		return nullptr;
}


void Planet::setCure(Cure* t_Cure)
{
	m_Cure = t_Cure;
}

Cure* Planet::getCure()
{
	return m_Cure;
}

void Planet::deleteCureAndDisease()
{
	m_Cure = nullptr;
	m_Disease = nullptr;
}

void Planet::DeleteRequest()
{
	m_Request = nullptr;
}

Planet::~Planet()
{
	if (m_Request != nullptr)
	{
		delete m_Request;
	}
	delete [] m_MemberList;

	if (m_Disease != nullptr)
	{
		m_Disease->~Disease();
	}

	if (m_Cure != nullptr)
	{
		m_Cure->~Cure();
	}
}

void Planet::update()
{
}