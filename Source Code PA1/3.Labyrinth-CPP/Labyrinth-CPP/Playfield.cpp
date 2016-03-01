#include "Playfield.h"
#include "FreeCell.h"
#include "OccupiedCell.h"
#include "RandomNumber/RandomNumberGenerator.h"

Playfield::Playfield( ImageProvider & imageProvider, int height, int width )
	: imageProvider( imageProvider ),
	height( height ), width( width ) {

	this->playfield = new Cell ** [ this->height ];
	for( int i = 0; i < this->height; i ++ ) {
		this->playfield[ i ] =  new Cell * [ this->width ];
	}
	
	this->generatePlayfield();
}

Playfield::~Playfield(void)
{
	this->clearPlayfield();

	for( int i = 0; i < this->height; i ++ ) {
		delete [] this->playfield[ i ];
	}
	
	delete [] this->playfield;
}

void Playfield::generatePlayfield( void ) {

	enum CellType {

		CELL_TYPE_FREE,
		CELL_TYPE_OCCUPIED,
		CELL_TYPE_MAX = CELL_TYPE_OCCUPIED
	};

	RandomNumberGenerator randomNumberGenerator;
	for( int y = 0; y < this->height; y ++ ) {
		for( int x = 0; x < this->width; x ++ ) {
			CellType cellType = static_cast<CellType> ( randomNumberGenerator.generate( CELL_TYPE_MAX ) );
			if( cellType == CELL_TYPE_FREE ) {
				this->playfield[ y ][ x ] = new FreeCell( this->imageProvider, Position( y, x ) );
			}
			else { // cellType == CELL_TYPE_OCCUPIED
				this->playfield[ y ][ x ] = new OccupiedCell( this->imageProvider, Position( y, x ) );
			}
		}
	}
}

void Playfield::clearPlayfield( void ) {
	// release memory for cells
	for( int y = 0; y < this->height; y ++ ) {
		for( int x = 0; x < this->width; x ++ ) {
			if( this->playfield[ y ][ x ] ) {
				delete this->playfield[ y ][ x ];
			}
		}
	}
}
	
void Playfield::regenerate( void ) {
	
	this->clearPlayfield();
	this->generatePlayfield();
}

void Playfield::draw ( Surface & surface ) {
	for( int y = 0; y < this->height; y ++ ) {
		for( int x = 0; x < this->width; x ++ ) {
			if( this->playfield[ y ][ x ] ) {
				this->playfield[ y ][ x ]->draw( surface );
			}
		}
	}
}

bool Playfield::onEdge( const Position & position ) {

	bool positionOnEdge = position.x == 0 || position.y == 0 ||
			position.x == this->width - 1 || position.y == this->height - 1;
	return positionOnEdge;
}

bool Playfield::onExit( const Position & position ) {

	bool  positionOnExit = this->onEdge( position );
	return positionOnExit;
}

Cell * Playfield::getCell( const Position & position ) const {

	Cell * cell = this->playfield[ position.y ][ position.x ];
	return cell;
}
