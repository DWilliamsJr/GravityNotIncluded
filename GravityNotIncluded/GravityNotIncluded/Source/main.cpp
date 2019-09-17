#include "PCH.h"
#include "Other/StateLibrary.h"
#include <windows.h> 

int main()
{	
	
	{
		Timer testTimer(__FILE__, __LINE__);

		StateLibrary testStateLibrary;

			// construct via new ALWAYS
			// Create a destructor for message
	/*	new message(_LOG, "this is a test ", __FILE__, __LINE__);
		new message(_ERROR, "this is a test2", __FILE__, __LINE__);
		new message(_WARN, "this is a test3", __FILE__, __LINE__);
		new message(_INFO, "this is a test4", __FILE__, __LINE__);		*/

		
	}
		message::printMessages(_TIMER);
	{
		Timer testTimer2(__FILE__, __LINE__);
		message::clear();
	}
		message::printMessages(_TIMER);
		
		


	system("pause");
}