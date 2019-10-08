#include "PCH.h"
#include "Other/Effect.h"
#include "GO/Entity.h"
/*
	Effect* m_Parent;

	Resources* ContributionEffect;
	Resources* ConsumptionEffect;

	bool AbilityToKill;
*/

Effect::Effect(Effect* t_parent)
{
	
	m_Parent = t_parent;
}

void Effect::SetContribution(Resources &temp)
{

	if (m_Parent != nullptr)
	{ 
		*ContributionEffect += m_Parent->GetContribution();
	}

	*ContributionEffect += &temp;

	}
void Effect::SetConsumption(Resources &temp)
{
	if (m_Parent != nullptr)
	{
		*ConsumptionEffect += m_Parent->GetConsumption();
	}

	*ConsumptionEffect += &temp;
}

void Effect::SetAbTK(bool temp)
{
	AbilityToKill = temp;
	}

Resources* Effect::GetContribution()
{
	if (ContributionEffect == nullptr && m_Parent != nullptr)
	{
		return m_Parent->GetContribution();
	}
	else
	{
		return ContributionEffect;
	}
}
Resources * Effect::GetConsumption()
{
	if (ConsumptionEffect == nullptr && m_Parent != nullptr)
	{
		return m_Parent->GetConsumption();
	}
	else
	{
		return ConsumptionEffect;
	}
}
bool Effect::GetAbTK()
{
	if (AbilityToKill == FALSE && m_Parent != nullptr)
	{
		return m_Parent->GetConsumption();
	}
	else
	{
		return AbilityToKill;
	}
}

void Effect::ApplyEffect(void* temp)
{
	Entity tempE = *((Entity*)temp);
	Resources tempR1 = tempE.getResConsumption();
	Resources tempR2 = tempE.getResContribution();
	tempR1 += ConsumptionEffect;
	tempR2 += ContributionEffect;
}

