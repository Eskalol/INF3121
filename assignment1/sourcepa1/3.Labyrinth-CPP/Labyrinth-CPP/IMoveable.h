#ifndef IMOVABLE_H
#define IMOVABLE_H

#include "Playfield.h"

class IMoveable {

public:

	enum Direction {
		DIRECTION_INVALID_DIRECTION,
		DIRECTION_LEFT,
		DIRECTION_UP,
		DIRECTION_RIGHT,
		DIRECTION_DOWN
	};
	
	virtual bool move( const Direction & direction, Playfield & playfield ) = 0;

};
#endif

