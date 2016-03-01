#include "Image.h"

#include <cstring>

Image::Image( const Point * data, int height, int width )
	: height( height ), width( width ) {
		
	this->data = new Point[ width * height ];
	memcpy( this->data, data, width * height );
	
}

Image::~Image( void ) {


	delete [] this->data;
}

void Image::draw( const Position & position, Surface & surface ) {
	




	surface.copyArea( position, this->data, this->height, this->width );
}

