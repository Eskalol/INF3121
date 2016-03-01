#include "Cursor.h"

#include <iostream>

Cursor::Cursor( const Position & position )
	: position( position ),
	movements( 0 ) {
}

bool Cursor::move( const Direction & direction, Playfield & playfield ) {

	this->movements ++;
	
	Position newPosition( this->position );
	
	switch ( direction ) {
		case IMoveable::DIRECTION_LEFT:
			newPosition.x --;
			break;
		case IMoveable::DIRECTION_UP:
			newPosition.y --;
			break;
		case IMoveable::DIRECTION_RIGHT:
			newPosition.x ++;
			break;
		case IMoveable::DIRECTION_DOWN:
			newPosition.y ++;
			break;
		default:
			std::cerr << "Invalid direction!" << std::endl;
	}
	
	Cell * cell = playfield.getCell( newPosition );
	bool successfulMove = cell->canGo();
	if( successfulMove ) {
		this->position = newPosition;
	}

	return successfulMove;
}	
	
	

Position Cursor::getPosition( void ) const {

	return this->position;
}

int Cursor::getMovements( void ) {

	return this->movements;
}
