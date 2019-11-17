#include "PCH.h"
#include "Comp/AI/Entity_AI.h"

extern StateLibrary *StaticStateLibrary;

Entity_AI::Entity_AI()
{
	message(_LOG, "CREATED NEW ENTITY_AI", __FILE__, __LINE__);
}

void Entity_AI::updateAI()
{
	std::string tempID = ParentEntity->peekState().getID();


		if (tempID.compare(StateIDList[HEALTHY]) == 0)
		{
			if (ParentEntity->getDisease() != nullptr )
			{
				message(_LOG, "New Entity State: Sick", __FILE__, __LINE__);
				ParentEntity->pushState(&StaticStateLibrary->GetState(SICK));
				return;
			}
			Resources *temp = &ParentEntity->getResContribution();
			Resources *tempConsume = &ParentEntity->getResConsumption();
			switch ((std::rand() % 100))
			{
			case 1:
			{
				if (tempConsume->Medicine != 0)
				{
					tempConsume->Medicine -= 1;
					temp->Wood += 1;
				}
				break;
			}
			case 2:
			{
				if (tempConsume->Wood != 0)
				{
					tempConsume->Wood -= 1;
					temp->Water += 1;
				}
				break;
			}
			case 3:
			{
				temp->Wood += 1;
				if (tempConsume->Food != 0)
				{
					tempConsume->Food -= 1;
					temp->Water += 1;
				}
				break;
			}
			case 4:
			{
				temp->Tech += 1;
				if (tempConsume->Water != 0)
				{
					tempConsume->Water -= 1;
					temp->Food += 1;
				}
				break;
			}
			case 5:
			{
				if (tempConsume->Tech != 0)
				{
					tempConsume->Tech -= 1;
				}
				temp->Medicine += 1;
				break;
			}
			default:
			{
				// UNLUCKY :)
			}
			}
		}
		else if (tempID.compare(StateIDList[SICK]) == 0)
		{
			Resources *TempContrib = &ParentEntity->getResContribution();
			Resources *tempConsume = &ParentEntity->getResConsumption();
			switch ((std::rand() % 10)+1)
			{
				case 1:
				{
					if (TempContrib->Food != 0)
					{
						TempContrib->Food -= 1;
					}
					break;
				}
				case 2:
				{
					if (TempContrib->Water != 0 )
					{
						TempContrib->Water -= 1; 
					}

					tempConsume->Food += 1;
					break;
				}
				case 3:
				{
					if (TempContrib->Wood != 0)
					{
						TempContrib->Food -= 1;
						TempContrib->Wood -= 1;
					}
					
					if (tempConsume->Water != 0)
					{
						tempConsume->Water -= 1;
					}
					break;
				}
				case 4:
				{
					if (TempContrib->Tech != 0)
					{
						TempContrib->Tech -= 1;
					}
					tempConsume->Medicine += 1;
					break;
				}
				case 5:
				{
					if (TempContrib->Medicine != 0)
					{
						TempContrib->Medicine -= 1;
					}
					break;
				}
				default:
				{
					// LUCKY :)
				}
			}
			if (ParentEntity->getDisease()->peekState().getID().compare(StateIDList[CURED]) == 0)
			{
				ParentEntity->popState();
				ParentEntity->setDisease(nullptr);
			}
			else if (ParentEntity->getDisease()->peekState().getID().compare(StateIDList[STAGETHREE]) == 0 && (std::rand() % 51) == 4)
			{
				message(_LOG, "New Entity State: Dead", __FILE__, __LINE__);
				ParentEntity->pushState(&StaticStateLibrary->GetState(DEAD));
			}
		}
		else if (tempID.compare(StateIDList[HUNGRY]) == 0)
		{
			// :) IDK YET
		}
		else if (tempID.compare(StateIDList[DEAD]) == 0)
		{
			Resources *temp = &ParentEntity->getResContribution();
			temp->Food = 0;
			temp->Water = 0;
			temp->Wood = 0;
			temp->Tech = 0;
			temp->Medicine = 0;
		}
	}

Entity* Entity_AI::getParent()
{
	return ParentEntity;
}

void Entity_AI::setParent(void* t_parent)
{
	 ParentEntity = (Entity*)t_parent;
	 ParentEntity->pushState(&StaticStateLibrary->GetState(HEALTHY));
}