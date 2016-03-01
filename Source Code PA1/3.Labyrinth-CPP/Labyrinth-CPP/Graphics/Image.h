#ifndef IMAGE_H
#define IMAGE_H

#include "Position.h"
#include "Surface.h"
#include "Point.h"

class Image {

public:
	Image( const Point * data, int height, int width );
	~Image( void );
	void draw( const Position & position, Surface & surface );

private:
	unsigned int height;
	unsigned int width;

	Point * data;
};

#endif

