#include "InputHandler.h"

void InputHandler::handleInput(
	std::string t_command,
	char t_text,
	std::vector<std::string> &t_undoList,
	std::vector<std::string> &t_redoList,
	std::string &t_word)
{
	if (t_command == "undo")
	{
		command = new UndoCommand();
	}
	else if (t_command == "redo")
	{
		command = new RedoCommand();
	}
	else {
		command = new TypeCommand();
	}
	command->execute(t_word,t_undoList,t_redoList, t_text);
	std::cout << t_word << std::endl;
}