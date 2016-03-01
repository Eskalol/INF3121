#include "Cell.h"

Cell::Cell( Image * image, const Position & position )
	: image( image ), position( position ) {
}

void Cell::draw( Surface & surface ) {

	this->image->draw( this->position, surface );
}

