#include "PCH.h"

#include "Comp/AI/Disease_AI.h"
#include "Comp/AI/Entity_AI.h"
#include "Comp/AI/Cure_AI.h"
#include "Comp/AI/Planet_AI.h"
#include "GO/Cure.h"
#include "GO/Disease.h"
#include "GO/Entity.h"
#include "GO/Planet.h"

class ObjectPool
{
private:
	enum CounterIndex
	{
		DiseaseCounter = 0, CureCounter, EntityCounter, PlanetCounter,
		EAICounter, CAICounter, DAICounter, PAICounter/*, ReqCounter*/,
		GraphicsCounter, PhysicsCounter, SoundCounter
	};

	struct PoolInfo
	{
		short MaxSize;
		bool* OccupiedFlag;
	};

	PoolInfo* Pool;
	Disease* Disease_Pool;	
	Cure* Cure_Pool;
	Entity* Entity_Pool;
	Planet* Planet_Pool;

	Entity_AI* EntityAI_Pool;
	Cure_AI* CureAI_Pool;
	Disease_AI* DiseaseAI_Pool;
	Planet_AI* PlanetAI_Pool;

	GraphicsComp* Graphics_Pool;
	PhysicsComp* Physics_Pool;
	SoundComp* Sound_Pool;

	int CheckAvalibility(const PoolInfo* t_pool);

public:
	ObjectPool(short DiseaseSize, short CureSize, short EntitySize, short PlanetSize,
		short EAISize,short CAISize, short DAISize, short PAISize/*, short ReqSize*/,
		short GraphicsSize, short PhysicsSize, short SoundSize);

	~ObjectPool();

	Disease* newDisease(short size);
	Cure* newCure(short size);
	Entity* newEntity();
	Planet* newPlanet();

	Entity_AI* newEntityAI();
	Cure_AI* newCureAI();
	Disease_AI* newDiseaseAI();
	Planet_AI* newPlanetAI();

	GraphicsComp* newGraphics();
	PhysicsComp* newPhysics();
	SoundComp* newSound();

	void onDestroy(GameObject &temp);
};