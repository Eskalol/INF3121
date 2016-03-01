#ifndef POSITION_H
#define POSITION_H

class Position {

public:
	Position( void );
	Position( int y, int x );
	Position( const Position & otherPosition );
	
	int y, x;
	
	static Position Center( int hight, int width );
};

bool operator==( const Position & position1, const Position & position2 );
bool operator!=( const Position & position1, const Position & position2 );

#endif

