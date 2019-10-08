#pragma once
#include "PCH.h"

class Effect
{
private:
	Effect* m_Parent;

	Resources* ContributionEffect;
	Resources* ConsumptionEffect;

	bool AbilityToKill;

public:
	
	Effect(Effect* t_parent);

	void SetContribution(Resources &temp);
	void SetConsumption(Resources &temp);
	void SetAbTK(bool temp);

	void ApplyEffect(void *Entity);

	Resources * GetContribution();
	Resources * GetConsumption();
	bool GetAbTK();

};