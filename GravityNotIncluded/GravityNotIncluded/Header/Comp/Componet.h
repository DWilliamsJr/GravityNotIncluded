#pragma once
#include "PCH.h"

class Componet
{
protected:
	PoolIndexInformation PoolInformation;
public:
	void setPoolInfo(short t_PoolIndex, short t_Index);
	PoolIndexInformation getPoolInfo();
};