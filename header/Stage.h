#ifndef STAGE_H
#define STAGE_H

#include "General.h"
#include "Stat.h"
#include "Weapon.h"

class Stage : public Stat {

public:

	// constructor

	Stage();

	Stage(string newName) {
		this->stageName = newName;
	}

	// destructor

	~Stage(); // deallocate all possible objects in the stage object. 


	// setters and getters

	void setWeaponsVector(vector<vector<Weapon>> newWeapVec) {

		this->allWeapons = newWeapVec;

	}

	vector<vector<Weapon>> * getWeaponsVector() {
		return &this->allWeapons;
	}

	string getStageName() {
		return this->stageName;
	}

	// TODO: getWeaponsVector: how to mnake this? pass a reference to the vector??


	// others


	

private:

	vector<vector<Weapon>> allWeapons; // each vector in the overall vector will hold a single type of weapon. 


	string stageName;

	// wins, losses, and totalGamesPlayed will be computed from the weapon data that is stored in the stage. 

	//vector<Weapon> weapons;


};

#endif

