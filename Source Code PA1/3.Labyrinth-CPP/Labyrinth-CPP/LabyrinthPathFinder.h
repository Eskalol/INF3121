#ifndef LABYRINTHPATHFINDER_H
#define LABYRINTHPATHFINDER_H

#include "Playfield.h"
#include "Graphics/Position.h"
#include "IMoveable.h"

#include <vector>

class LabyrinthPathFinder {

public:
	LabyrinthPathFinder( Playfield & playfield );
	bool findPath( Position position );

private:
	bool alreadyTried( const Position & position );
	void rememberPosition( Position position );

	bool  move( const IMoveable::Direction & direction, const Position & startPosition,  Position & endPosition );

	Playfield & playfield;
	std::vector<Position> triedPositions;

};

#endif
