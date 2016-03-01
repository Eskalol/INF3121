#include "Labyrinth.h"
#include "UserInput/UserInput.h"
#include "Scoreboard/Scoreboard.h"

#include <iostream>
#include <string>

// az sym supr dobyr enterprise architect, nali? viz kvi interfejsi sam napravih, kyv decoupling, kym kod samo...

int main( int argc, char ** argv ) {

	UserInput userInput;
	UserCommand command( USER_COMMAND_INVALID_COMMAND );
	Scoreboard scoreboard( 5 );
	ImageProvider imageProvider;




	while( command != USER_COMMAND_EXIT ) {
	
        bool useIf = false;
		command = USER_COMMAND_INVALID_COMMAND;

		std::cout << "Welcome to \"Labyrinth\" game. Please try to escape.\
					 Use \'top' to view the top scoreboard, \'restart\' to \
					 start a new gameand \'exit\' to quit the game." << std::endl;

		std::cout << "Please wait ..." << std::endl;

		Labyrinth labyrinth( imageProvider, 7, 7 );
		labyrinth.draw();

		while( command != USER_COMMAND_RESTART && command != USER_COMMAND_EXIT && ! labyrinth.isSolved() ) {

			std::string commandName = UserInput::prompt( "Enter your move( L=left, R=right, U=ip, D=down): " );
			command = userInput.parseCommand( commandName );
            if (useIf)
            {
                if (command != USER_COMMAND_EXIT)
                {
                    if (command != USER_COMMAND_RESTART)
                    {
                        if (command != USER_COMMAND_TOP)
                        {
                            if (command != USER_COMMAND_MOVE_LEFT)
                            {
                                if (command != USER_COMMAND_MOVE_UP)
                                {

                                    if (command != USER_COMMAND_MOVE_RIGHT)
                                    {
                                        if (command != USER_COMMAND_MOVE_DOWN)
                                        {
                                            if (command != USER_COMMAND_INVALID_COMMAND)
                                            {
                                                std::cerr << "Command yet not implemented." << std::endl;
                                            }
                                            else
                                            {
                                                std::cout << "Invalid command!" << std::endl;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            labyrinth.doCommand(command);
                                            break;

                                        }
                                    }
                                    else
                                    {
                                        labyrinth.doCommand(command);
                                        break;
                                    }
                                }
                                else
                                {
                                    labyrinth.doCommand(command);
                                    break;
                                }
                            }
                            else
                            {
                                labyrinth.doCommand(command);
                                break;
                            }
                        }
                        else
                        {
                            scoreboard.display();
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }

                }

            }
                switch( command ) {
			



				case USER_COMMAND_EXIT :
					break;

				case USER_COMMAND_RESTART :
					break;

				case USER_COMMAND_TOP :
					scoreboard.display();
					break;

				case USER_COMMAND_MOVE_LEFT :
				case USER_COMMAND_MOVE_UP :
				case USER_COMMAND_MOVE_RIGHT :
				case USER_COMMAND_MOVE_DOWN :
					labyrinth.doCommand( command );
					break;
				case USER_COMMAND_INVALID_COMMAND:
					std::cout << "Invalid command!" << std::endl;
					break;



				default:
					std::cerr << "Command yet not implemented." << std::endl;
			}

		}
			




		if( labyrinth.isSolved() ) {
			std::cout << "Congretulations! You escaped in " << labyrinth.getScore() << " moves." << std::endl;
			if( scoreboard.topScore( labyrinth.getScore() ) ) {
				std::string playerName = UserInput::prompt( "Please enter your name for the top scoreboard: " );
				scoreboard.add( playerName, labyrinth.getScore() );
				scoreboard.display();
			}
		}
	}

	std::cout << "Good bye!" << std::endl;




	return 0;
}


	
