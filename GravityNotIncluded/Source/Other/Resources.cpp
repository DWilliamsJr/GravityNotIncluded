#include "PCH.h"
#include "Other/Resources.h"
Resources::Resources()
{
	Food = 0;;

	Water = 0;

	Tech = 0;

	Wood = 0;

	Medicine = 0;
}

void Resources::setResources(int t_food, int t_water, int t_tech, int t_wood, int t_meds)
{
	Food += t_food;;

	 Water += t_water;

	 Tech += t_tech;

	 Wood += t_wood;

	 Medicine += t_meds;
}