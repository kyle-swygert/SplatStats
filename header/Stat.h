#ifndef STAT_H
#define STAT_H

#include "General.h"


class Stat {

public:

	
	// constructor
	Stat();
	Stat(int newWins, int newLosses);


	// destructor
	~Stat();

	// others
	int computeTotalGamesPlayed() {
		// function computes the total number of games played, as well as setting the number of games played in the class itself. 
		this->totalGamesPlayed = (this->getWins() + this->getLosses());

		return this->totalGamesPlayed;
	}

	double computeWinRate() {
		// compute win rate, store value into the class, and returns the value of winrate. 
		this->winRate = ((double) this->getWins() / (double) this->computeTotalGamesPlayed());

		return this->winRate;
	}

	double computeLossRate() {
		this->lossRate = ((double) this->getLosses() / (double) this->computeTotalGamesPlayed());

		return this->lossRate;
	}




	// setters and getters
	void setWins(int newWins) {
		this->wins += newWins;
	}

	int getWins() const {
		return this->wins;
	}

	void resetWins() {
		this->wins = 0;
	}

	void setLosses(int newLosses) {
		this->losses += newLosses;
	}

	int getLosses() const {
		return this->losses;
	}

	void resetLosses() {
		this->losses = 0;
	}




private:

	int wins;
	int losses;
	int totalGamesPlayed;
	// these below values will calculated eachtime, rather than being stored as data. 
	double winRate; // wins/totalGamesPlayed
	double lossRate; // losses/totalGamesPlayed

};

#endif