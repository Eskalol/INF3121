#ifndef IDWAWABLE_H
#define IDWAWABLE_H

#include "Graphics/Surface.h"
#include "Graphics/Position.h"

class IDrawable {

public:
	virtual void draw ( Surface & surface ) = 0;
};

#endif

