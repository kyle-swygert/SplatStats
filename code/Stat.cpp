#include "Stat.h"

Stat::Stat()
{
	this->wins = 0;
	this->losses = 0;
	this->totalGamesPlayed = 0;
	this->winRate = 0.0;
	this->lossRate = 0.0;
}

Stat::Stat(int newWins, int newLosses) {

	Stat();

	this->setWins(newWins);
	this->setLosses(newLosses);

	this->computeTotalGamesPlayed();

	this->computeLossRate();
	this->computeWinRate();
}

Stat::~Stat()
{
	// nothing goes inside here, no pointers are allocated in the Stat class. 


}