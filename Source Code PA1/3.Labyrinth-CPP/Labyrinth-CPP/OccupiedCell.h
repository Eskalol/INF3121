#ifndef OCCUPIEDCELL_H
#define OCCUPIEDCELL_H

#include "Cell.h"
#include "Graphics/ImageProvider.h"

class OccupiedCell
	: public Cell {

public:
	OccupiedCell( ImageProvider & imageProvider, const Position & position );
	bool canGo( void );
};
#endif

