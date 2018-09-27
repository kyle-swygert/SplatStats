#include "Weapon.h"

Weapon::Weapon() {

	Stat();

	this->numKills = 0;
	this->numOfAssists = 0;
	this->numSpecialDeploys = 0;
	this->totalPointsEarned = 0;

	this->weaponName = "PlaceholderName";

}

Weapon::Weapon(string newName, int newWins, int newLosses, int newPoints, int newAssists, int newKills, int newSpecialDeploy) {

	*this = Weapon();

	this->setWeaponName(newName);
	this->setWins(newWins);
	this->setLosses(newLosses);
	this->setPointsEarned(newPoints);
	this->setNumAssists(newAssists);
	this->setNumKills(newKills);
	this->setSpecialDeploy(newSpecialDeploy);

}

Weapon::Weapon(string newName) {

	*this = Weapon();

	this->setWeaponName(newName);

}


Weapon::~Weapon() {

	// nothing written here yet. update this later to do the appropriate thing. 


}