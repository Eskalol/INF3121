#include "RandomNumberGenerator.h"

#include <cstdlib>
#include <ctime>

RandomNumberGenerator::RandomNumberGenerator( void ) {

	time_t currentTime = time( NULL );
	srand( currentTime ); // change random sequence
}

unsigned int RandomNumberGenerator::generate( unsigned int range ) {
	
	return rand() % ( range + 1 );
}
