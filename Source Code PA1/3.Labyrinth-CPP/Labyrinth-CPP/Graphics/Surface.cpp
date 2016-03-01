#include "Surface.h"

#include <iostream>

Surface::Surface( int height, int width )
	: height( height ), width( width ) {
		
	this->surface = new Point * [ this->height ];
	for( unsigned int i = 0; i < this->height; i ++ ) {
		this->surface[ i ] =  new Point [ this->width ];
	}
}

Surface::~Surface( void ) {

	for( unsigned int i = 0; i < this->height - 1; i ++ ) {
		delete [] this->surface[ i ];
	}
	delete [] this->surface;
}

void Surface::copyPoint( const Position & position, const Point & point ) {
	this->surface[  position.y ][  position.x ] = point;
}

void Surface::copyArea( const Position & position, const Point * area, int height, int width ) {

	int x = position.x;
	int y = position.y;

	for( int yOffset = 0; yOffset < height; yOffset ++ ) {
		for( int xOffset = 0; xOffset < width; xOffset ++ ) {
			this->surface[ y + yOffset ][ x + xOffset ] = area[ yOffset * width + xOffset ];
		}
	}
}

void Surface::drawOnScreen( void ) {

	for( unsigned int y = 0; y < this->height; y ++ ) {
		for( unsigned int x = 0; x < this->width; x ++ ) {
			this->surface[ y ][ x ].drawOnScreen();
		}
		std::cout << std::endl;
	}
}


