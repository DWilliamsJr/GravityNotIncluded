#pragma once

#include "PCH.h"

class Resources
{
public:
	int Food;

	int Water;

	int Tech;

	int Wood;

	int Medicine;

	Resources();
	void setResources(int t_food, int t_water, int t_tech, int t_wood, int t_meds);
};