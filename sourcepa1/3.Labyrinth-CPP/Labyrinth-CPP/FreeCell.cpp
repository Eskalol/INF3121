#include "FreeCell.h"

FreeCell::FreeCell( ImageProvider & imageProvider, const Position & position )
	: Cell( imageProvider.getImage( "free" ) , position ) {
}

bool FreeCell::canGo( void ) {
	
	return true;
}
