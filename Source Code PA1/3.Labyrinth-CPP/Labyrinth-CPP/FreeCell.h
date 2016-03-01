#ifndef FREECELL_H
#define FREECELL_H

#include "Cell.h"
#include "Graphics/ImageProvider.h"

class FreeCell 
	: public Cell {

public:
	FreeCell( ImageProvider & imageProvider, const Position & position );
	bool canGo( void );
};
#endif

