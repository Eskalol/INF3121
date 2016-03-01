#ifndef CURSOR_H
#define CURSOR_H

#include "IMoveable.h"
#include "Graphics/Position.h"

class Cursor
	: public IMoveable {

public:
	Cursor( const Position & position );
	Position getPosition( void ) const;
	int getMovements( void ); 
	bool move( const Direction & direction, Playfield & playfield );

private:
	Position position;
	unsigned int movements;
};

#endif
