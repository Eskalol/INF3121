#ifndef SCOREBOARD_H
#define SCOREBOARD_H


#include <list>
#include <string>

typedef int Score;

class Scoreboard {

public:
	Scoreboard( int size );

	bool topScore( const Score & score );
	void add( const std::string & name, const Score & score );
	void display( void );

private:
	struct ScoreboardItem {
		std::string name;
		Score score;

		ScoreboardItem( void )
			: name( "" ), score( 0 ) {}
		ScoreboardItem( const std::string & name, Score score )
			: name( name ), score( score ) {}
		ScoreboardItem( const ScoreboardItem & scoreboardItem )
			: name( scoreboardItem.name ), score( scoreboardItem.score ) {}
		static bool compare( const ScoreboardItem & first, const ScoreboardItem & second );
	};

	typedef std::list<ScoreboardItem> ScoreboardList;
	ScoreboardList scoreboard;

	unsigned int size;

};

#endif

