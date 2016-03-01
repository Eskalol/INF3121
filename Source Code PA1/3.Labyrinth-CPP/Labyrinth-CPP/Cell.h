#ifndef CELL_H
#define CELL_H

#include "IDrawable.h"
#include "Graphics/Image.h"

class Cell
	: public IDrawable {

public:
	Cell( Image * image, const Position & position );
	virtual bool canGo( void ) = 0;
	void draw( Surface & surface );

private:
	Image * image;
	Position position;
};

#endif

