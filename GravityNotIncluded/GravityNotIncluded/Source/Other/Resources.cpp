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

void Resources::setResources(int fo, int wat, int te, int wood, int med)
{
	Food += fo;

	Water += wat;

	Tech += te;

	Wood += wood;

	Medicine += med;
}
void Resources::operator += ( Resources* res)
{
	Food += res->Food;

	Water += res->Water;

	Tech += res->Tech;

	Wood += res->Wood;

	Medicine += res->Medicine;
}

void Resources::operator -= (Resources* res)
{
	Food -= res->Food;

	Water -= res->Water;

	Tech -= res->Tech;

	Wood -= res->Wood;

	Medicine -= res->Medicine;
}