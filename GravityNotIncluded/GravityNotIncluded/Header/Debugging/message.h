#include "PCH.h"
#pragma once
#include <windows.h> 


class message
{
private:

public:
	message(short t_Color, std::string t_text, std::string t_file, short t_line);
	message();
	short Priority();
	void ToString();


		//MESSAGEMANAGER
	static void printMessages(short t_priority);
	static void addMessage(message &t_message);
	static void clear();

protected:
	short m_TextColor;
	std::string m_File;
	short m_Line;
	std::string m_Text;


	

};