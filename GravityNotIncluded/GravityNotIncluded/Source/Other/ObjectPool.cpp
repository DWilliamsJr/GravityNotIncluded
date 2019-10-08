#include "PCH.h"
#include "Other/ObjectPool.h"

ObjectPool::ObjectPool(short DiseaseSize, short CureSize, short EntitySize, short PlanetSize,
	short EAISize, short CAISize, short DAISize, short PAISize/*, short ReqSize*/,
	short GraphicsSize, short PhysicsSize, short SoundSize)
{
	
	Disease_Pool = (Disease*)malloc(DiseaseSize* sizeof (Disease));
	Cure_Pool = (Cure*)malloc(CureSize*sizeof(Cure));
	Entity_Pool = (Entity*)malloc(EntitySize*sizeof(Entity));
	Planet_Pool = (Planet*)malloc(PlanetSize * sizeof(Planet));

	EntityAI_Pool = (Entity_AI*)malloc(EAISize* sizeof(Entity_AI));
	CureAI_Pool = (Cure_AI*)malloc(CAISize * sizeof(Cure_AI));
	DiseaseAI_Pool = (Disease_AI*)malloc(DAISize * sizeof(Disease_AI));
	PlanetAI_Pool = (Planet_AI*)malloc(PAISize * sizeof(Planet_AI));

	Graphics_Pool = (GraphicsComp*)malloc(GraphicsSize* sizeof(GraphicsComp));
	Physics_Pool = (PhysicsComp*)malloc(PhysicsSize * sizeof(PhysicsComp));
	Sound_Pool = (SoundComp*)malloc(SoundSize* sizeof(SoundComp));

	Pool = new PoolInfo[SoundCounter + 1];

	Pool[DiseaseCounter].MaxSize = DiseaseSize;
	Pool[CureCounter].MaxSize = CureSize;
	Pool[EntityCounter].MaxSize = EntitySize;
	Pool[PlanetCounter].MaxSize = PlanetSize;

	Pool[EAICounter].MaxSize = EAISize;
	Pool[CAICounter].MaxSize = CAISize;
	Pool[DAICounter].MaxSize = DAISize;
	Pool[PAICounter].MaxSize = PAISize;

	Pool[GraphicsCounter].MaxSize = GraphicsSize;
	Pool[PhysicsCounter].MaxSize = PhysicsSize;
	Pool[SoundCounter].MaxSize = SoundSize;

	for (int x = 0; x <= SoundCounter; x++)
	{
		Pool[x].OccupiedFlag = new bool[Pool[x].MaxSize]();
	}
}

int ObjectPool::CheckAvalibility(const PoolInfo* t_pool)
{
	for (int x = 0; x < t_pool->MaxSize; x++)
	{
		if (t_pool->OccupiedFlag[x] == FALSE)
		{
			return x;
		}
	}
	return -1;
}


Disease* ObjectPool::newDisease(short size)
{
	int temp = CheckAvalibility(&Pool[DiseaseCounter]);

	if (temp == -1)
	{
		 message(_ERROR, "DISEASE POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[DiseaseCounter].OccupiedFlag[temp] = true;
		Disease* tempDisease = new(Disease_Pool + temp) Disease(size, newDiseaseAI());
		tempDisease->setPoolInfo(DiseaseCounter, temp);
		return tempDisease;
	}
}
Cure* ObjectPool::newCure(short size)
{
	int temp = CheckAvalibility(&Pool[CureCounter]);

	if (temp == -1)
	{
		 message(_ERROR, "CURE POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[CureCounter].OccupiedFlag[temp] = true;
		Cure* tempCure = new(Cure_Pool + temp) Cure(size, newCureAI());
		tempCure->setPoolInfo(CureCounter, temp);
		return tempCure;
	}
}

Entity* ObjectPool::newEntity()
{
	int temp = CheckAvalibility(&Pool[EntityCounter]);

	if (temp == -1)
	{
		 message(_ERROR, "ENTITY POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[EntityCounter].OccupiedFlag[temp] = true;

		Entity *tempEntity = new(Entity_Pool + temp)  Entity(newEntityAI());
		tempEntity->setPoolInfo(EntityCounter, temp);
		return tempEntity;
	}
}

Planet* ObjectPool::newPlanet()
{
	int temp = CheckAvalibility(&Pool[PlanetCounter]);

	if (temp == -1)
	{
		message(_ERROR, "PLANET POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[PlanetCounter].OccupiedFlag[temp] = true;

		Planet *tempPlanet = new(Planet_Pool + temp)  Planet(newPlanetAI(), newPhysics(), newSound(), newGraphics());
		tempPlanet->setPoolInfo(PlanetCounter, temp);
		return tempPlanet;
	}
}


Entity_AI* ObjectPool::newEntityAI()
{
	int temp = CheckAvalibility(&Pool[EAICounter]);

	if (temp == -1)
	{
		message(_ERROR, "ENTITY_AI POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[EAICounter].OccupiedFlag[temp] = true;
		Entity_AI* tempAI = new(EntityAI_Pool + temp) Entity_AI;
		tempAI->setPoolInfo(EAICounter, temp);
		return tempAI;
	}
}
Cure_AI* ObjectPool::newCureAI()
{
	int temp = CheckAvalibility(&Pool[CAICounter]);

	if (temp == -1)
	{
		message(_ERROR, "CURE_AI POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[CAICounter].OccupiedFlag[temp] = true;
		Cure_AI *tempAI = new(CureAI_Pool + temp)  Cure_AI;
		tempAI->setPoolInfo(CAICounter, temp);
		return tempAI;
	}
}

Disease_AI* ObjectPool::newDiseaseAI()
{
	int temp = CheckAvalibility(&Pool[DAICounter]);

	if (temp == -1)
	{
		message(_ERROR, "DISEASE_AI POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[DAICounter].OccupiedFlag[temp] = true;
		Disease_AI *tempAI = new(DiseaseAI_Pool + temp)  Disease_AI();
		tempAI->setPoolInfo(DAICounter, temp);
		return tempAI;
	}
}

Planet_AI* ObjectPool::newPlanetAI()
{
	int temp = CheckAvalibility(&Pool[PAICounter]);

	if (temp == -1)
	{
		message(_ERROR, "PLANET_AI POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[PAICounter].OccupiedFlag[temp] = true;
		Planet_AI *tempAI = new(PlanetAI_Pool + temp)  Planet_AI();
		tempAI->setPoolInfo(PAICounter, temp);
		return tempAI;
	}
}

GraphicsComp* ObjectPool::newGraphics()
{
	int temp = CheckAvalibility(&Pool[GraphicsCounter]);

	if (temp == -1)
	{
		message(_ERROR, "GRAPHICS POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[GraphicsCounter].OccupiedFlag[temp] = true;
		GraphicsComp* tempGraphics = new(Graphics_Pool + temp) GraphicsComp;
		tempGraphics->setPoolInfo(GraphicsCounter, temp);
		return tempGraphics;
	}
}

PhysicsComp* ObjectPool::newPhysics()
{
	int temp = CheckAvalibility(&Pool[PhysicsCounter]);

	if (temp == -1)
	{
		message(_ERROR, "PHYSICS POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[PhysicsCounter].OccupiedFlag[temp] = true;
		PhysicsComp* tempPhysics = new(Physics_Pool + temp) PhysicsComp;
		tempPhysics->setPoolInfo(PhysicsCounter, temp);
		return tempPhysics;
	}
}

SoundComp* ObjectPool::newSound()
{
	int temp = CheckAvalibility(&Pool[SoundCounter]);

	if (temp == -1)
	{
		message(_ERROR, "SOUND POOL FULL", __FILE__, __LINE__);
		return nullptr;
	}
	else
	{
		Pool[SoundCounter].OccupiedFlag[temp] = true;
		SoundComp* tempSound = new(Sound_Pool + temp) SoundComp;
		tempSound->setPoolInfo(SoundCounter, temp);
		return tempSound;
	}
}

void ObjectPool::onDestroy(GameObject &temp)
{
	PoolIndexInformation tempInfo;
	if (temp.getAI() != nullptr)
	{
		tempInfo = temp.getAI()->getPoolInfo();
		Pool[tempInfo.PoolIndex].OccupiedFlag[tempInfo.Location] = false;
	}
	if (temp.getGraphics() != nullptr)
	{
		tempInfo = temp.getGraphics()->getPoolInfo();
		Pool[tempInfo.PoolIndex].OccupiedFlag[tempInfo.Location] = false;
	}
	if (temp.getsound() != nullptr)
	{
		tempInfo = temp.getsound()->getPoolInfo();
		Pool[tempInfo.PoolIndex].OccupiedFlag[tempInfo.Location] = false;
	}
	if (temp.getPhysics() != nullptr)
	{
		tempInfo = temp.getPhysics()->getPoolInfo();
		Pool[tempInfo.PoolIndex].OccupiedFlag[tempInfo.Location] = false;
	}

		Pool[temp.getPoolInfo().PoolIndex].OccupiedFlag[temp.getPoolInfo().Location] = false;
}

ObjectPool::~ObjectPool()
{
	free((void*)Disease_Pool);
	free((void*)Cure_Pool);
	free((void*)Entity_Pool);
	free((void*)Planet_Pool);

	free((void*)EntityAI_Pool);
	free((void*)CureAI_Pool);
	free((void*)DiseaseAI_Pool);
	free((void*)PlanetAI_Pool);

	free((void*)Graphics_Pool);
	free((void*)Physics_Pool);
	free((void*)Sound_Pool);
}