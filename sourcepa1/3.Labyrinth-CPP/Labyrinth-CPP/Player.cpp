#include "Player.h"

Player::Player(ImageProvider & imageProvider, const Position & position )
	: image( imageProvider.getImage( "player" ) ),
	Cursor( position ) {
}

void Player::draw( Surface & surface ) {

	this->image->draw( this->getPosition(), surface );
}


