#ifndef SURFACE_H
#define SURFACE_H

#include "Position.h"
#include "Point.h"

class Surface {

public:
	Surface( int height, int width );
	~Surface( void );
	void copyPoint( const Position & position, const Point & point );
	void copyArea( const Position & position, const Point * area, int height, int weigth );
	void drawOnScreen( void );

private:
	unsigned int height;
	unsigned int width;

	Point ** surface;
};

#endif

