#include "ImageProvider.h"

#include <map>
#include <string>

ImageProvider::ImageProvider(void) {
	images[ "free" ] = new Image( & Point( '-' ), 1, 1 );
	images[ "occupied" ] = new Image( & Point( 'X' ), 1, 1  );
	images[ "player" ] = new Image( & Point( '*' ), 1, 1  );
}

ImageProvider::~ImageProvider(void) {
	std::map<std::string, Image *>::iterator pos;
	for (pos = images.begin(); pos != images.end(); ++pos) {
		delete pos->second;
	}
}

Image * ImageProvider::getImage( const std::string & imageName ) {
	
	return images[ imageName ];
}
