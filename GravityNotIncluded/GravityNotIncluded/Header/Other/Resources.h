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

	void operator += ( Resources* res);

	void operator -= (Resources* res);

	void setResources(int fo, int wat, int te, int wood, int med);
};