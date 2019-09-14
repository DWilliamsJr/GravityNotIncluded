#include <iostream>
#include <windows.h> 


#include "PCH.h"
#include "Debugging/messageManager.h"

static messageManager dispach(10);

int main()
{	
	
	{
		Timer testTimer(__FILE__, __LINE__);

		message test(_LOG, "this is a test ", __FILE__, __LINE__);
		message test2(_LOG, "this is a test2", __FILE__, __LINE__);

		dispach.addMessage(test);
		dispach.addMessage(test2);

		dispach.printMessages(_LOG);
		dispach.printMessages(_ERROR);
	}
	system("pause");
}