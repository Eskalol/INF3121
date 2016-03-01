#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include "Image.h"

#include <map>
#include <string>

class ImageProvider {

public:
	ImageProvider(void);
	~ImageProvider(void);

	Image * getImage( const std::string & imageName );

private:
	std::map<std::string, Image *> images;	
};
#endif

