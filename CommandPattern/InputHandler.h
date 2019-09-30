#ifndef INPUTHANDLER
#define INPUTHANDLER
#include "Command.h"
#include "SFML/Graphics.hpp"
#include <iostream>
class InputHandler
{
public:
	void handleInput(
		std::string t_command,
		char m_text, 
		std::vector<std::string> &t_undoList,
		std::vector<std::string> &t_redoList,
		std::string &t_word);

private:
	Command* command;
};
#endif
