#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include "Cell.h"
#include "IDrawable.h"
#include "Graphics/ImageProvider.h"

class Playfield
	: public IDrawable {

public:
	Playfield( void );
	Playfield( ImageProvider & imageProvider, int height, int width );
	~Playfield(void);
	
	void regenerate( void );
	bool onExit( const Position & position );
	void draw ( Surface & surface );
	Cell * getCell( const Position & position ) const;

private:
	Cell *** playfield;
	int width;
	int height;
	
	ImageProvider & imageProvider;

	bool onEdge( const Position & position );
	void generatePlayfield( void );
	void clearPlayfield( void );
};
#endif


