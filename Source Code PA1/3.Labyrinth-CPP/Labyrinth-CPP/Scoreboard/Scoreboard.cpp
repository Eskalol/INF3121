#include "Scoreboard.h"

#include <iostream>

bool Scoreboard::ScoreboardItem::compare( const ScoreboardItem & first, const ScoreboardItem & second ) {

	if( first.score < second.score ) {
		return true;
	}
	else {
		return false;
	}
}

Scoreboard::Scoreboard( int size )
	: size( size ) {
}

bool Scoreboard::topScore( const Score & score ) {

	bool isTopScore = false;
	if( this->scoreboard.size() == this->size ) {
		isTopScore = this->scoreboard.back().score > score;
	}
	else {
		isTopScore = true;
	}

	return isTopScore;
}
	
void Scoreboard::add( const std::string & name, const Score & score ) {
	
	if( this->scoreboard.size() < this->size ) {
		this->scoreboard.push_back( ScoreboardItem( name, score ) );
		this->scoreboard.sort( ScoreboardItem::compare );
	}
	else {

		ScoreboardItem & scoreboardItem = this->scoreboard.back();
	
		if( scoreboardItem.score > score ) {
			this->scoreboard.push_back( ScoreboardItem( name, score ) );
			this->scoreboard.sort( ScoreboardItem::compare );
			this->scoreboard.pop_back();
		}
	}
}

void Scoreboard::display( void ) {

	int number = 1;
	for ( ScoreboardList::iterator scoreboardItem = this->scoreboard.begin();
		scoreboardItem != this->scoreboard.end(); scoreboardItem ++ ) {
		
		std::cout << number << ". " << 
			scoreboardItem->name << " --> " << 
			scoreboardItem->score << " moves" << std::endl;
		number ++;
	}
}


