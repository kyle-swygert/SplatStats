#ifndef TRACKER_H
#define TRACKER_H

#include "General.h"
#include "Stage.h"

class Tracker : public Stat {
public:

	// constructor
	Tracker(); // loads the user data, as well as creates the BSTs from the files. 

	// destructor
	~Tracker(); // saves all data possible, deletes the trees, then deallocates the memory for the object. 

	// others
	void loadUserData(); // this function will read and store all data from the userData.csv file

	void printTitle(); // prints an ascii art title. 

	void printStatusLine() const {

		switch (this->statusLineOption) {

		case 0: // detailed design
			cout << "Playing: " << this->getCurrGameMode() << " on " << this->getCurrStage() << " with the " << this->getCurrWeapon() << endl;
			break;

		case 1: // minimal design
			cout << this->getCurrGameMode() << ": " << this->getCurrStage() << " -> " << this->getCurrWeapon() << endl;
			break;

		}

	}

	void inputData();

	void editData();

	void viewData();

	void editSettings();

	void addWeapon();

	void addStage();

	void storeAllData(); // write all data to the text files. include the data in the UserData.csv file as well. 

	void runApp();

	void printOverallStats();

	// setters and getters
	// make getter functions into const functions. 
	void setUserName(string name) {
		this->userName = name;
	}

	string getUserName() const {
		return this->userName;
	}

	void setCurrGameMode(string gameMode) {
		this->currGameMode = gameMode;
	}

	string getCurrGameMode() const {
		return this->currGameMode;
	}

	void setCurrStage(string stage) {
		this->currStage = stage;
	}

	string getCurrStage() const {
		return this->currStage;
	}

	void setCurrWeapon(string weapon) {
		this->currWeapon = weapon;
	}

	string getCurrWeapon() const {
		return this->currWeapon;
	}

	void setProgramVersion(string newProgramVersion) {
		this->programVersion = newProgramVersion;
	}

	string getProgramVersion() const {
		return this->programVersion;
	}

	
private:

	string userName;
	string currGameMode;
	string currStage; // should this be a stage reference?
	string currWeapon; // should this be a weapon reference?


	string programVersion;

	vector<string> weaponTypeNames;


	int statusLineOption; // sets how the status line will appear when printed. 

	// vectors of stages that represent the different gamemodes. 

	// regular
	vector<Stage> TurfWar;
	// ranked
	vector<Stage> Rainmaker;
	vector<Stage> TowerControl;
	vector<Stage> SplatZone;
	vector<Stage> ClamBlitz;

};

#endif