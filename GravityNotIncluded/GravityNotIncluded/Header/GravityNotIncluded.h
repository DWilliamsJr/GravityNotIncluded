#pragma once
#include "PCH.h"

#include "Other/ObjectPool.h"
#include "GO/Planet.h"
#include "Comp/AI/Planet_AI.h"
#include <thread>

class GravityNotIncluded
{
private:
	Planet **PlanetList;

	ObjectPool *TempPool;

	Resources UserResources;

	bool DirtyFlag;
	std::string UserInput;

	void ProcessAI();
	void ProcessSound();
	void ProcessPhysics();
	
	void DeleteGO(GameObject *t_GO);
	void ConstructWorld();
	void CreateNewGO(Planet *t_Planet);

public:

	GravityNotIncluded();
	~GravityNotIncluded();
	void GameLoop();
	void getInput();
	void processInput();
};