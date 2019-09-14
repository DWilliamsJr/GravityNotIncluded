#pragma once

#include "PCH.h"
#include <windows.h> 


class messageManager
{
private:
	HANDLE  hConsole;

	message *Messages;
	short index;
	short maxSize;

public:
	messageManager(short size);
	~messageManager();

	void printMessages(short t_priority);

	void addMessage(message &t_message);
	void clear();

};