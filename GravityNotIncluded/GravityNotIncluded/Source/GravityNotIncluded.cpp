#include "PCH.h"
#include "Other/SM/StateLibrary.h"
#include "..\Header\GravityNotIncluded.h"

StateLibrary* StaticStateLibrary = new StateLibrary();


GravityNotIncluded::GravityNotIncluded()
{	
	TempPool = new ObjectPool(NumDisease, NumCure, NumEntity, NumPlanet, NumEAI, NumCAI, NumDAI, NumPAI, NumGraphics, NumPhysics, NumSound);
	StaticStateLibrary->init();
	PlanetList = new Planet*[NumPlanet]();
	ConstructWorld();
	UserInput = "";
	DirtyFlag = false;
	UserResources.Food = 0;
	UserResources.Water = 0;
	UserResources.Wood = 0;
	UserResources.Tech = 0;
	UserResources.Medicine = 0;
}


void GravityNotIncluded::GameLoop()
{
	Timer tempTimer;
	std::ostringstream SS;
	std::string temp;
	double Elapsed;
	std::clock_t StartTime = std::clock();
	std::cout << "Enter 'COMMANDS' to view all avaliable commands. (please type in all caps)" << std::endl;

	while (true)
	{
		processInput();
		Elapsed = (std::clock() - StartTime) / (double)CLOCKS_PER_SEC;
		if (Elapsed > 1.0f)
		{
			Elapsed = 0;
			StartTime = std::clock();
			ProcessAI();
			
			message::printMessages(_TestGame);
			message::clear();
		}
	}
}

void GravityNotIncluded::getInput()
{
	std::string temp;
	std::getline(std::cin, temp);

	UserInput = temp;
	DirtyFlag = true;
}

void GravityNotIncluded::processInput()
{
	if (DirtyFlag == true)
	{
		DirtyFlag = false;

		int buffer = 500;
		for (int x = 0; x < NumPlanet; x++)
		{
			if (UserInput.compare("STATUS " + PlanetList[x]->getID()) == 0)
			{
				std::string temp = "Resources on planet: " +  PlanetList[x]->getID() + ", Food: " + std::to_string(PlanetList[x]->getResources().Food) + ", Water: " +
					std::to_string(PlanetList[x]->getResources().Water) + ", Tech: " + std::to_string(PlanetList[x]->getResources().Tech) + ", Meds: " +
					std::to_string(PlanetList[x]->getResources().Medicine) + ", Wood " + std::to_string(PlanetList[x]->getResources().Wood);
				message(_TestGame, temp, __FILE__, __LINE__);

				temp = "State of planet: " + PlanetList[x]->getID() + " " + PlanetList[x]->peekState().getID();
				message(_TestGame, temp, __FILE__, __LINE__);
				return;

			}

			else if (UserInput.compare("COLLECT RESOURCES FROM " + PlanetList[x]->getID()) == 0)
			{
						Resources *temp = &PlanetList[x]->getResources();

						if (temp->Food - buffer > buffer)
						{
							UserResources.Food = UserResources.Food + (temp->Food - buffer);
							temp->Food = temp->Food - (temp->Food - buffer);
						}
						if (temp->Water - buffer > buffer)
						{
							UserResources.Water = UserResources.Water + (temp->Water - buffer);
							temp->Water = temp->Water - (temp->Water - buffer);
						}
						if (temp->Wood - buffer > buffer)
						{
							UserResources.Wood = UserResources.Wood + (temp->Wood - buffer);
							temp->Wood = temp->Wood - (temp->Wood - buffer);
						}
						if (temp->Tech - buffer > buffer)
						{
							UserResources.Tech = UserResources.Tech + (temp->Tech - buffer);
							temp->Tech = temp->Tech - (temp->Tech - buffer);
						}
						if (temp->Medicine - buffer > buffer)
						{
							UserResources.Medicine = UserResources.Medicine + (temp->Medicine - buffer);
							temp->Medicine = temp->Medicine - (temp->Medicine - buffer);
						}

						message(_TestGame, "Successfully collected resources from " + PlanetList[x]->getID(), __FILE__, __LINE__);
						return;
			}

			else if (UserInput.compare("GIVE RESOURCES TO " + PlanetList[x]->getID()) == 0)
			{
				Resources *temp = &PlanetList[x]->getResources();

				if (UserResources.Food > buffer  && temp->Food < buffer)
				{
					temp->Food = temp->Food + (buffer - temp->Food);
					UserResources.Food = UserResources.Food - (buffer - temp->Food);
				}
				if (UserResources.Water > buffer && temp->Water < buffer)
				{
					temp->Water = temp->Water + (buffer - temp->Water);
					UserResources.Water = UserResources.Water - (buffer - temp->Water);
				}
				if (UserResources.Wood > buffer && temp->Wood < buffer)
				{
					temp->Wood = temp->Wood + (buffer - temp->Wood);
					UserResources.Wood = UserResources.Wood - (buffer - temp->Wood);
				}
				if (UserResources.Medicine > buffer && temp->Medicine < buffer)
				{
					temp->Medicine = temp->Medicine + (buffer - temp->Medicine);
					UserResources.Medicine = UserResources.Medicine - (buffer - temp->Medicine);
				}
				if (UserResources.Tech > buffer && temp->Tech < buffer)
				{
					temp->Tech = temp->Tech + (buffer - temp->Tech);
					UserResources.Tech = UserResources.Tech - (buffer - temp->Tech);
				}
				message(_TestGame, "Successfully gave resources to " + PlanetList[x]->getID(), __FILE__, __LINE__);
				return;
			}
		}

		if (UserInput.compare("COMMANDS") == 0)
		{
			std::string temp = "\nCOMMANDS - View all avaliable commands\n"
				"STATUS - Recieve an update on Player Resource Pool and any planets in Critical State\n"
				"COLLECT RESOURCES FROM (PLANET) - Add surplus resources from (Planet) to User Resource Pool\n"
				"GIVE RESOURCES TO (PLANET) - Give (PLANET) enough resources to meet Critical State Threshold\n"
				"STATUS (PALNET) - Check the Resource Pool and State of (PLANET)\n"
				"LIST- List all planets\n";
			message(_TestGame, temp, __FILE__, __LINE__);
		}
		
		else if (UserInput.compare("LIST") == 0)
		{
			std::string temp = "\n";
			for (int x = 0; x < NumPlanet; x++)
			{
				temp = temp + PlanetList[x]->getID() +"\n";
			}
			message(_TestGame, temp, __FILE__, __LINE__);
		}
		
		else if (UserInput.compare("STATUS") == 0)
		{
			std::string temp = "User Resources:  Food: " + std::to_string(UserResources.Food) + ", Water: " +
				std::to_string(UserResources.Water) + ", Tech: " + std::to_string(UserResources.Tech) + ", Meds: " +
				std::to_string(UserResources.Medicine) + ", Wood " + std::to_string(UserResources.Wood);
			message(_TestGame, temp, __FILE__, __LINE__);

			for (int x = 0; x < NumPlanet; x++)
			{
				if (PlanetList[x]->peekState().getID().compare(StateIDList[EPIDEMIC]) == 0)
				{
					message(_TestGame, PlanetList[x]->getID() + " State: " + PlanetList[x]->peekState().getID(), __FILE__, __LINE__);
				}
			}
		}

		else
		{
			message(_TestGame, "Invalid input, Type 'COMMANDS' To see all avaliable commands", __FILE__, __LINE__);
		}
		
	}
}

void GravityNotIncluded::ProcessAI() 
{
	for (int x = 0; x < NumPlanet; x++)
	{
		if (PlanetList[x] == nullptr)
		{
			continue;
		}

		CreateNewGO(PlanetList[x]);
		if (PlanetList[x]->getDisease() != nullptr)
		{
			PlanetList[x]->getDisease()->getAI()->updateAI();
		}

		if (PlanetList[x]->getCure() != nullptr)
		{
			PlanetList[x]->getCure()->getAI()->updateAI();
		}

		for (int y = 0; y < MEMBERLISTSIZE; y++)
		{
			if (PlanetList[x]->getMember(y) == nullptr)
			{
				continue;
			}

			PlanetList[x]->getMember(y)->getAI()->updateAI();
			if (PlanetList[x]->getMember(y)->peekState().getID().compare(StateIDList[DEAD]) == 0)
			{
				message(_LOG, PlanetList[x]->getID() + ": Entity Died", __FILE__, __LINE__);
				DeleteGO(PlanetList[x]->getMember(y));
				PlanetList[x]->getMember(y)->~Entity();
				PlanetList[x]->removeMember(y);
			}
		}
		PlanetList[x]->getAI()->updateAI();
	}
}

void GravityNotIncluded::ProcessSound() {}
void GravityNotIncluded::ProcessPhysics() {}

void GravityNotIncluded::DeleteGO(GameObject *t_GO) 
{
	TempPool->onDestroy(*t_GO);
}
void GravityNotIncluded::ConstructWorld() 
{
	PlanetList[0] = TempPool->newPlanet();
	PlanetList[0]->setID("MERCURY");

	PlanetList[1] = TempPool->newPlanet();
	PlanetList[1]->setID("VENUS");

	PlanetList[2] = TempPool->newPlanet();
	PlanetList[2]->setID("EARTH");

	PlanetList[3] = TempPool->newPlanet();
	PlanetList[3]->setID("MARS");

	PlanetList[4] = TempPool->newPlanet();
	PlanetList[4]->setID("JUPITER");

	PlanetList[5] = TempPool->newPlanet();
	PlanetList[5]->setID("SATURN");

	PlanetList[6] = TempPool->newPlanet();
	PlanetList[6]->setID("URANUS");

	PlanetList[7] = TempPool->newPlanet();
	PlanetList[7]->setID("NEPTUNE");

	PlanetList[8] = TempPool->newPlanet();
	PlanetList[8]->setID("PLUTO");

}


void GravityNotIncluded::CreateNewGO(Planet *t_Planet)
{
	std::string t_message = t_Planet->getAI()->updateMessage;
	if (t_message.compare("") == 0)
	{
		return;
	}

	if (t_message.compare("CREATE NEW CURE") == 0)
	{
		message(_LOG, "Create New Cure. On Planet: " + t_Planet->getID(), __FILE__, __LINE__);
		t_Planet->setCure(TempPool->newCure(5));
	}
	else if (t_message.compare("CREATE NEW DISEASE") == 0)
	{
		message(_LOG, "Create New Disease. On Planet: " + t_Planet->getID(), __FILE__, __LINE__);
		t_Planet->setDisease(TempPool->newDisease(5));
	}
	else if (t_message.compare("CREATE NEW ENTITY") == 0)
	{
		if (t_Planet->CheckAvalibility() == TRUE)
		{
			message(_LOG, "Create New Entity. On Planet: " + t_Planet->getID() , __FILE__, __LINE__);
			Entity *temp = TempPool->newEntity();
			t_Planet->addMember(temp);
		}
	}
	else if (t_message.compare("DELETE DISEASE") == 0)
	{
		message(_LOG, "Deleted Disease And Cure. On Planet: " + t_Planet->getID(), __FILE__, __LINE__);
		DeleteGO(t_Planet->getDisease());
		t_Planet->getDisease()->~Disease();
		DeleteGO(t_Planet->getCure());
		t_Planet->getCure()->~Cure();
		t_message = "DELETE REQUEST";
		t_Planet->deleteCureAndDisease();
	}
	if (t_message.compare("DELETE REQUEST") == 0)
	{
		delete t_Planet->getRequest();
		t_Planet->DeleteRequest();
	}
	t_Planet->getAI()->updateMessage = "";
}


GravityNotIncluded::~GravityNotIncluded()
{
	for (int x = 0; x < NumPlanet; x++)
	{
		if (PlanetList[x] == nullptr)
		{
			continue;
		}
		PlanetList[x]->~Planet();
	}
	delete[] PlanetList;
	delete TempPool;
}
