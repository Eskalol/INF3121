#include "Position.h"

Position::Position(void)
	: y ( 0 ), x ( 0 ) {
}
Position::Position ( int y, int x )
	: y ( y ), x ( x ) {
}
Position::Position( const Position & otherPosition )
	: y ( otherPosition.y ), x ( otherPosition.x ) {
}

Position Position::Center( int height, int width ) {

	return Position( height / 2 + 1 - 1, width / 2 + 1 - 1 );
}

bool operator==( const Position & position1, const Position & position2 ) {

	return position1.x == position2.x && position1.y == position2.y;
}

bool operator!=( const Position & position1, const Position & position2 ) {

	return position1.x != position2.x || position1.y != position2.y;
}

