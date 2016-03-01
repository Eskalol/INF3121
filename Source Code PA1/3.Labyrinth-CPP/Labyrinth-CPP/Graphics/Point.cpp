#include "Point.h"

#include <iostream>

Point::Point( void )
		: value ( 0 ) {
}
Point::Point( char value )
		: value ( value ) {
}

void Point::drawOnScreen( void ) {
	
	std::cout << this->value;
}
