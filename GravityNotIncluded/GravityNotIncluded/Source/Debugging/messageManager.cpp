#include "Debugging/messageManager.h"

messageManager::messageManager(short size)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	maxSize = size;
	index = 0;
	Messages = new message[size];
}

void messageManager::printMessages(short t_priority)
{
	for(int x = 0; x <index; x++)
	{
		//std::cout << "HELLO???" << std::endl;
		if (Messages[x].Priority() == t_priority)
		{
			FlushConsoleInputBuffer(hConsole);
			SetConsoleTextAttribute(hConsole, Messages[x].Priority());

			Messages[x].ToString();
		}
	}
	SetConsoleTextAttribute(hConsole, _LOG);
}

void messageManager::addMessage(message &t_message)
{
	if (index < maxSize)
	{
	Messages[index] = t_message;
	index++;
	}
	else
	{
		std::cout << "MANAGER FULL" << std::endl;
	}

}

void messageManager::clear()
{
	index = 0;
}

messageManager::~messageManager()
{
	delete [] Messages;
}