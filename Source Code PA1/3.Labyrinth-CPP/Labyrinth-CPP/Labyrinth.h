#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <vector>

#include "Player.h"
#include "Playfield.h"
#include "Scoreboard/Scoreboard.h"
#include "UserInput/UserInput.h"

class Labyrinth {

public:
	Labyrinth( ImageProvider & imageProvider, int height, int width );
	void doCommand( const UserCommand & command );
	Score getScore( void );
	bool isSolved( void );
	void draw ( void );

private:
	Player player;
	Playfield playfield;
	Surface surface;
	bool solved;

	std::vector<IDrawable *> objectsToDraw;
};

#endif
