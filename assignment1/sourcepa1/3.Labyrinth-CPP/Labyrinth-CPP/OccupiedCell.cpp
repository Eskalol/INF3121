#include "OccupiedCell.h"

OccupiedCell::OccupiedCell( ImageProvider & imageProvider, const Position & position )
	: Cell( imageProvider.getImage( "occupied" ) , position ) {
}

bool OccupiedCell::canGo( void ) {




	return false;
}

