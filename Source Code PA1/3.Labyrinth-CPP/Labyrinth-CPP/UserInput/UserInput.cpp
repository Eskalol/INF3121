#include "UserInput.h"

#include <iostream>

UserInput::UserInput(void) {

	this->commands[ "exit" ] = USER_COMMAND_EXIT;
	this->commands[ "restart" ] = USER_COMMAND_RESTART;
	this->commands[ "top" ] = USER_COMMAND_TOP;
	this->commands[ "L" ] = USER_COMMAND_MOVE_LEFT;
	this->commands[ "l" ] = USER_COMMAND_MOVE_LEFT;
	this->commands[ "U" ] = USER_COMMAND_MOVE_UP;
	this->commands[ "u" ] = USER_COMMAND_MOVE_UP;
	this->commands[ "R" ] = USER_COMMAND_MOVE_RIGHT;
	this->commands[ "r" ] = USER_COMMAND_MOVE_RIGHT;
	this->commands[ "D" ] = USER_COMMAND_MOVE_DOWN;
	this->commands[ "d" ] = USER_COMMAND_MOVE_DOWN;
}

std::string UserInput::prompt( const std::string & message ) {

	std::cout << message;
	
	std::string userInput;
	std::cin >> userInput;
	return userInput;
}

UserCommand UserInput::parseCommand( const std::string & commandName ) {

	UserCommand command = USER_COMMAND_INVALID_COMMAND;
	CommandTable::iterator commandPosition = this->commands.find( commandName );
	if( commandPosition != this->commands.end() ) {
		command = commandPosition->second;
	}

	return command;
}

void UserInput::printCommand( UserCommand command ) {

	switch( command ) {
	
		case USER_COMMAND_EXIT :
			std::cout << "USER_COMMAND_EXIT" << std::endl;
			break;

		case USER_COMMAND_RESTART :
			std::cout << "USER_COMMAND_RESTART" << std::endl;
			break;

		case USER_COMMAND_TOP :
			std::cout << "USER_COMMAND_TOP" << std::endl;
			break;

		case USER_COMMAND_MOVE_LEFT :
			std::cout << "USER_COMMAND_MOVE_LEFT" << std::endl;
			break;

		case USER_COMMAND_MOVE_UP :
			std::cout << "USER_COMMAND_MOVE_UP" << std::endl;
			break;

		case USER_COMMAND_MOVE_RIGHT :
			std::cout << "USER_COMMAND_MOVE_RIGHT" << std::endl;
			break;

		case USER_COMMAND_MOVE_DOWN :
			std::cout << "USER_COMMAND_MOVE_DOWN" << std::endl;
			break;

		default:
			std::cout << "USER_COMMAND_INVALID_COMMAND" << std::endl;
	}
}

