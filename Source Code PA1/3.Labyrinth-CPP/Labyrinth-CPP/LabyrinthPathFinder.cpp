#include "LabyrinthPathFinder.h"
#include "Cursor.h"
#include <iostream>
#include <algorithm>
LabyrinthPathFinder::LabyrinthPathFinder( Playfield & playfield )
	: playfield( playfield ) {}
bool LabyrinthPathFinder::alreadyTried( const Position & position ) {	
	bool positionAlreadyTried = false;
	if( find( this->triedPositions.begin(),  this->triedPositions.end(), position ) != this->triedPositions.end() ) {
		positionAlreadyTried = true;
	}
	return positionAlreadyTried;
}
void LabyrinthPathFinder::rememberPosition( Position position ) {	
	this->triedPositions.push_back( position );
}
bool LabyrinthPathFinder::move( const IMoveable::Direction & direction, const Position & startPosition,  Position & endPosition ) {
	
	Cursor cursor( startPosition );
	bool successfulMove = cursor.move( direction, this->playfield );
	endPosition = cursor.getPosition();
	return successfulMove;
}
bool LabyrinthPathFinder::findPath( Position position ) {
	Cell * cell = this->playfield.getCell( position );
	if( ! cell->canGo() ) { /* cannot be here */
		return false;
	}
	if ( alreadyTried( position ) ) {
		return false;
	}
	if ( this->playfield.onExit( position ) ) {
		return true;
	}
	rememberPosition( position );
		Position newPosition;
		if ( move( IMoveable::DIRECTION_LEFT, position, newPosition ) ) {
		if ( findPath( newPosition ) ) {
			return true;
		}
	}
		if ( move( IMoveable::DIRECTION_UP, position, newPosition ) ) {
		if ( findPath( newPosition ) ) {
			return true;
		}
	}
	if ( move( IMoveable::DIRECTION_RIGHT, position, newPosition ) ) {
		if ( findPath( newPosition ) ) {
			return true;
		}
	}
	if ( move( IMoveable::DIRECTION_DOWN, position, newPosition ) ) {
		if ( findPath( newPosition ) ) {
			return true;
		}
	}
	return false;
}