#include "PCH.h"
#include "Comp/AI/Cure_AI.h"

extern StateLibrary *StaticStateLibrary;

Cure_AI::Cure_AI()
{
	 message(_LOG, "CREATED NEW CURE_AI", __FILE__, __LINE__);
}


void Cure_AI::updateAI()
{
		if (ParentCure->peekState().getID().compare(StateIDList[INPROGRESS]) == 0)
		{
			for(int x = 0; x < 5; x++)
			{
				if (ParentCure->getSequence()[x] == NULL)
				{
					ParentCure->setSequence(x, 'a' + (std::rand() % 26));
					return;
				}
			}
			message(_LOG, "New Cure State: COMPLETED", __FILE__, __LINE__);
			ParentCure->pushState(&StaticStateLibrary->GetState(COMPLETED));
			return;
		}
	}

Cure* Cure_AI::getParent()
{
	return ParentCure;
}

void Cure_AI::setParent(void* t_parent)
{
	ParentCure = (Cure*)t_parent;
	ParentCure->pushState(&StaticStateLibrary->GetState(INPROGRESS));
}