#pragma once 

#include "PCH.h"

#include "Componet.h"


class GraphicsComp : public Componet
{
private:
	unsigned int BufferID;

public:
	~GraphicsComp();
	void init(float* T_Verticies);
	void update();
};