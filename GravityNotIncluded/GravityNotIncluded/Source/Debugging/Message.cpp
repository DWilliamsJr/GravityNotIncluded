#include "Debugging/message.h"

message::message(short t_Color, std::string t_text, std::string t_file, short t_line)
{
	m_TextColor = t_Color;
	m_Text = t_text;
	m_File = t_file;
	m_Line = t_line;
}

message::message() {}

short message::Priority()
{
	return m_TextColor;
}
void message::ToString()
{
	std::cout << m_File.c_str() << " : Line " << m_Line << ": \n\tMessage: " << m_Text.c_str() <<"\n" << std::endl;
}