#ifndef COMMAND
#define COMMAND
#include <SFML/Graphics.hpp>
#include <iostream>
class Command
{
public:
	virtual ~Command() {}
	virtual void execute(std::string& t_word, std::vector<std::string>& t_undoList,
		std::vector<std::string>& t_redoList, char t_char) = 0;

private:
	//std::vector<char> m_list;
	//std::string m_word;
};

class TypeCommand : public Command
{
public:

	void execute(std::string &t_word, std::vector<std::string>& t_undoList,
		std::vector<std::string>& t_redoList, char t_char)
	{
		//m_list.push_back(t_char);
		t_undoList.push_back(t_word);
		t_word += t_char;
		t_redoList.clear();
	};
};

class UndoCommand : public Command
{
public:

	void execute(std::string& t_word, std::vector<std::string>& t_undoList,
		std::vector<std::string>& t_redoList, char t_char)
	{
		//m_list.push_back(t_char);
		if (t_undoList.size() != 0)
		{
			t_redoList.push_back(t_word);
			t_word = t_undoList.back();
			t_undoList.pop_back();
		}
	};
};

class RedoCommand : public Command
{
public:

	void execute(std::string& t_word, std::vector<std::string>& t_undoList,
		std::vector<std::string>& t_redoList, char t_char)
	{
		//m_list.push_back(t_char);
		if (t_redoList.size() != 0)
		{
			t_undoList.push_back(t_word);
			t_word = t_redoList.back();
			t_redoList.pop_back();
		}
	};
};
#endif