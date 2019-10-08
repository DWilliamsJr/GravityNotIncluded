#include "PCH.h"
#include "Comp/Componet.h"

void Componet::setPoolInfo(short t_PoolIndex, short t_Index)
{
	PoolInformation.PoolIndex = t_PoolIndex;
	PoolInformation.Location = t_Index;
}

PoolIndexInformation Componet::getPoolInfo()
{
	return PoolInformation;
}
