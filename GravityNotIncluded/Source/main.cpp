#include "PCH.h"

#include "Comp/AI/Entity_AI.h"
#include "GO/Entity.h"
#include "GravityNotIncluded.h"

extern StateLibrary *StaticStateLibrary;

int main()
{	

	StaticStateLibrary->init();

	Entity tempEntity;
	Entity_AI tempAi;
	tempAi.setParent(tempEntity);

	tempEntity.setID("TOD");
	std::cout << tempAi.getParent()->getID() << std::endl;


	message::printMessages(_TIMER);


	system("pause");
}