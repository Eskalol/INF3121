#ifndef PLAYER_H
#define PLAYER_H

#include "Cursor.h"
#include "IDrawable.h"
#include "Graphics/ImageProvider.h"

class Player
	: public IDrawable, public Cursor {

public:
	Player( ImageProvider & imageProvider, const Position & position );
	void draw( Surface & surface );

private:
	Image * image;
};
#endif

