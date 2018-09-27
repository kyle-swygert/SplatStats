#ifndef WEAPON_H
#define WEAPON_H

#include "General.h"
#include "Stat.h"

class Weapon : public Stat {

public:

	// constructor
	Weapon();
	Weapon(string newName, int newWins, int newLosses, int newPoints, int newAssists, int newKills, int newSpecialDeploy);
	Weapon(string newName);

	// destructor
	~Weapon(); // deallocate all the neccessary objects within the weapon object. 


	// setters and getters

	void setPointsEarned(int newPoints) {
		this->totalPointsEarned = newPoints;
	}

	int getPointsEarned() const {
		return this->totalPointsEarned;
	}

	void setNumAssists(int newAssist) {
		this->numOfAssists = newAssist;
	}

	int getNumAssists() const {
		return this->numOfAssists;
	}

	void setNumKills(int newKills) {
		this->numKills = newKills;
	}

	int getNumKills() const {
		return this->numKills;
	}

	void setSpecialDeploy(int newSpecial) {
		this->numSpecialDeploys = newSpecial;
	}

	void setWeaponName(string newName) {
		this->weaponName = newName;
	}
	
	string getWeaponName() const {
		return this->weaponName;
	}


	// others




private:
	string weaponName;

	int totalPointsEarned;
	int numOfAssists;
	int numKills;
	int numSpecialDeploys;

};

#endif