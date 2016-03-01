#ifndef USERINPUT_H
#define USERINPUT_H

#include <string>
#include <map>

enum UserCommand {

	USER_COMMAND_INVALID_COMMAND,
	USER_COMMAND_EXIT,
	USER_COMMAND_RESTART,
	USER_COMMAND_TOP,
	USER_COMMAND_MOVE_LEFT,
	USER_COMMAND_MOVE_UP,
	USER_COMMAND_MOVE_RIGHT,
	USER_COMMAND_MOVE_DOWN
};

class UserInput {

public:
	UserInput( void );

	static std::string prompt( const std::string & message );
	UserCommand parseCommand( const std::string & commandName );

	void printCommand( UserCommand command );

private:
	typedef std::map<std::string, UserCommand> CommandTable;
	CommandTable commands;

};

#endif
