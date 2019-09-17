#include "PCH.h"

#include "GameObject.h"
//#include "Planet_AI.h"
#include "Entity.h"

class Planet: public GameObject
{
private:
	std::vector<Entity> m_MemberList;

	Resources m_ResourcePool;

	Request* m_Request;

	std::stack<State> m_State;

	//Planet_AI* m_AI;

public:
	Planet();

	void addMember(Entity *t_Entity);

	void pushState(State *T_State);

	State* peekState();

	State* popState();

	Entity* getMember(short index);

	Resources& getResources();

	Request* getRequest();

	void GameObject::update();

};