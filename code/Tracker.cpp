#include "Tracker.h"

Tracker::Tracker() {


	Stat(); // initialize the inherited Stat object data. 


	// open all of the files to be processed. 
	fstream userData("UserData.csv"),
		stages("Stages.csv"),
		weapons("Weapons.csv"),
		data("Data.csv"),
		turfwar("TurfwarData.csv"),
		rainmaker("RainmakerData.csv"),
		towercontrol("TowerControlData.csv"),
		splatzone("SplatZoneData.csv"),
		clamblitz("ClamBlitzData.csv"),
		*curFile;


	// load the addresses of the data files into a vector for loading all the data into the data structure. 
	vector<fstream *> dataFiles(5);
	dataFiles[0] = &turfwar;
	dataFiles[1] = &rainmaker;
	dataFiles[2] = &towercontrol;
	dataFiles[3] = &splatzone;
	dataFiles[4] = &clamblitz;


	// make a temporary vector to refer to the gamemode vectors in the tracker object for construction use only. 
	vector<vector<Stage> * > gameModes(5);
	gameModes[0] = &this->TurfWar;
	gameModes[1] = &this->Rainmaker;
	gameModes[2] = &this->TowerControl;
	gameModes[3] = &this->SplatZone;
	gameModes[4] = &this->ClamBlitz;

	vector<Stage> curGameMode;

	/*
	
	// regular
	vector<Stage> TurfWar;
	// ranked
	vector<Stage> Rainmaker;
	vector<Stage> TowerControl;
	vector<Stage> SplatZone;
	vector<Stage> ClamBlitz;
	
	
	*/


	string tempStr = "";

	const char *emptyStr = "\n"; // used as reference to test if a string is empty. 

	getline(userData, tempStr, ',');
	this->setUserName(tempStr);

	getline(userData, tempStr, ',');
	this->setCurrGameMode(tempStr);

	getline(userData, tempStr, ',');
	this->setCurrStage(tempStr);

	getline(userData, tempStr, ',');
	this->setCurrWeapon(tempStr);

	getline(userData, tempStr, ',');
	this->setProgramVersion(tempStr);

	getline(userData, tempStr);
	this->statusLineOption = stoi(tempStr);



	userData.close();

	// open and close all files to read from in this function only. 

	// create a blank vector of stages and weapons that hold only the names of the two categories. these vectors will be copied to store the data, then the blank vectors will be deleted at the end of the constructor function. 

	int outerIndex = 0;

	//char peekInt = '\0';

	vector<vector<Weapon>> tempWeapVec(7); // TODO: the number of weapon categories is hard coded here, try to see if this can be avoided. 
	vector<Stage> tempStageVec;

	//vector<vector<Weapon>> *outerIt = &tempWeapVec;
	vector<Weapon> *innerIt = &tempWeapVec[0];
 


	// weapIt is used to access individual vectors in the vector of vectors.
	// use the dereference operator to access the data. (*)


	
	// building blank stage vector
	while (stages.peek() != EOF) {
		// insert entry with name into the vector
		getline(stages, tempStr);
		tempStageVec.push_back(Stage(tempStr)); // create a stage object with the tempStr, then insert it into the list. 

		tempStr.clear();
	}

	// stage vector is filled

	tempStr.clear();



	// building blank weapon vector
	while (weapons.peek() != EOF) {

		
		

		innerIt = &tempWeapVec[outerIndex];


		// for each weapon type in the file, read in the weapon name, then populate the vector with all of the weapon names, then move on to the next weapon type. 


		// read and store the weapon type being processed. 
		getline(weapons, tempStr);
		weaponTypeNames.push_back(tempStr);

		/*
		weapon order in file:

		brella
		chargers
		dualies
		rollers
		shooters
		sloshers
		splatlings

		*/



		while (weapons.peek() != *emptyStr) {
			// loop while the line to be processed is not empty.

			getline(weapons, tempStr);
			innerIt->push_back(Weapon(tempStr));

		}

		getline(weapons, tempStr);

		++outerIndex;

	}

	tempStr.clear();

	cout << "blank template vectors should be filled" << endl;

	// now all the stages in the blank vector need to have the blank weapon vector added to each of the stages. 

	// copying the weapon vector to all of the stages in the stages vector. 
	for (int i = 0; i < tempStageVec.size(); ++i) {

		// copy the weapon vector to all the stage vectors. 
		tempStageVec[i].setWeaponsVector(tempWeapVec);

	}

	
	// make copies of the tempStageVector and set them for all the gamemodes in the Tracker object. 
	this->ClamBlitz = tempStageVec;
	this->TurfWar = tempStageVec;
	this->TowerControl = tempStageVec;
	this->SplatZone = tempStageVec;
	this->Rainmaker = tempStageVec;
	



	// TODO: Now the data must be loaded into the constructed gamemode and stage and weapon vectors. 

	// read the data from data.csv and add the values to the data structures. 


	/*
	
	data.csv format

	~,0,0,0,0,0,0
	
	~, wins, losses, totalPointsEarned, numAssists, numKills, numSpecialDeploys



				*** '~' represents the stage name that is omitted ***
	


	*/



	string curWeapon = "";
	string token = "";
	stringstream weapStream(curWeapon);
	stringstream tokenStream(token);

	//char * curWeapon = "";

	// use tempStr as a string for the current stage data being handled

	int stageNumber = 0;

	vector<vector<Weapon>>  * veryTempWeapVec;
	


	// new data loop attempt
	// data file loop
	for (int fileNum = 0; fileNum < dataFiles.size(); ++fileNum) {

		// change the data file that is being processed. 
		curFile = dataFiles[fileNum];

		// change the gamemode data that is being stored into
		curGameMode = *gameModes[fileNum];




		// weapon Type loop
		for (int weapTypeNum = 0; weapTypeNum < this->weaponTypeNames.size(); ++weapTypeNum) {

			// read in the weapon type, but dont do anything with the data. this should read the whole line. 
			getline(*curFile, tempStr);

			cout << "Weapon Type: " << tempStr << endl << endl;

			cout << "Number of weapons:" << tempWeapVec[weapTypeNum].size() << endl << endl;


			// number of weapons loop
			for (int weapNum = 0; weapNum < tempWeapVec[weapTypeNum].size(); ++weapNum) {


				// read in the data for the current weapon that is being processed. this should read the whole line. 
				getline(*curFile, curWeapon); 

				// currWeapon now holds all of the data for the current weapon. 

				cout << "Current data beign processed: " << curWeapon << endl;

				weapStream.str(curWeapon);


				//weapStream(curWeapon); // trying to set the stream with a new string. 

				getline(weapStream, tempStr, '~'); // consume the very first '~' of the line of data. 

				//tempStr.clear();

				//token.clear();
				token = ""; // reset the value of the token string. 

				// number of stages loop
				for (int stageNum = 0; stageNum < tempStageVec.size(); ++stageNum) {

					

					// process the contents of curWeapon string object. 
					// tokenize the data into smaller parts. 

					// break down string into data between the '~' chars, then store the appropriate data to the correct place. 

					// use weapStream to manipulate the string


					cout << "stage number:" << stageNum;

					getline(weapStream, token, '~');

					

					// token now holds the data that is to be read. 
					// remove the commas at the front and end of the token string. 

					if (token[0] == ',') { // remove comma at front of the string. 
						token.erase(0, 1); // erases 1 char, starting at position 0. 
					}

					if (token.back() == ',') { // remove comma ad the end of the string. 
						token.pop_back(); // deletes the last char in the string. 
					}

					cout << " -> part of data line: " << token << endl;

					tokenStream.str(token);

					// ACTUAL STRING PROCESSING BEGINS HERE!!!! ALL FORMATTING IS COMPLETE!!!!

					// use tokenStream to manipulate the token string. 


					/*
					
					wins
					losses
					total points earned
					num assists
					num kills
					num special deploys
					
					*/



					// this is the old line that still had a bug in it. 
					//(curGameMode[stageNum].getWeaponsVector())[weapTypeNum][weapNum][weapNum].setLosses(23);
					//(curGameMode[stageNum].getWeaponsVector())[weapTypeNum][weapTypeNum][weapNum].setLosses(23);


					// NOTE: understand why this code does not access the correct items after the first large iteration...
					(curGameMode[stageNum].getWeaponsVector())[0][weapTypeNum][weapNum].setLosses(23);
					//(curGameMode[5].getWeaponsVector())[0][2][3].setLosses(23);

					getline(tokenStream, tempStr, ',');
					curGameMode[stageNum].setWins(stoi(tempStr));
					

					getline(tokenStream, tempStr, ',');
					// uncomment the statement belowafter testing. it might have been messing up my testing of the program. 
					curGameMode[stageNum].setLosses(stoi(tempStr)); 


					getline(tokenStream, tempStr, ',');
					
					

					getline(tokenStream, tempStr, ',');

					

					getline(tokenStream, tempStr, ',');

					

					getline(tokenStream, tempStr, ',');

					






					tokenStream.clear(); // clear the stream for reuse in the future. 

					//tempStr.clear();


				} // end of stages loop

				
				curWeapon.clear(); // clear the string obj, just to be safe. 

				weapStream.clear(); // clear the stream obj to be able to reuse the stream in the future. 

				

			} // end of weapon number loop

			getline(*curFile, tempStr); // consumes the empty line in the data file. 

		} // end of weapon type loop

		cout << endl << endl << "motha succ, this is the end of a single file that is being processed!!" << endl << endl << endl;

	} // end of data file loop





	cout << "end of new data reading loop test" << endl;


	
	

	//// old data loop attempt
	//for (int i = 0; i < 5; ++i) {


	//	// TODO: gameModes vector holds all the game mode stage vectors. 



	//	curFile = dataFiles[i];
	//	// pointer is now pointing to the current file that is to be processed

	//	curGameMode = *gameModes[i];


	//	// weapon type loop
	//	for (int x = 0; x < this->weaponTypeNames.size(); ++x) {

	//		getline(*curFile, tempStr, '\n');
	//		// weapon type is read into program


	//		// TODO: this line is not processing correctly after the first loop. the second loop processes incorrectly. 
	//		cout << "\nweapon Type being Processed: " << endl << tempStr << endl << endl;

	//		// TODO: I think that I need another loop. the 2 for loops right now will only read in the data from the first line of the first weapon in all of the data files....

	//		/* TODO:
	//		in the end, we need loops for:

	//		*data files
	//		*number of stages
	//		-number of weapons
	//		*number of weapon Types

	//		*/


	//		// number of weapons loop. use the int x to determine the weapon Type being processed. 
	//		for (int y = 0; y < tempWeapVec[y].size(); ++y) {

	//			cout << "\nnumber of weapons: " << tempWeapVec[y].size() << endl;

	//			// number of stages loop
	//			for (int j = 0; j < tempStageVec.size(); ++j) {


	//				// print name of stage that the data belongs to. 
	//				cout << "stage name: " << (*gameModes[i])[j].getStageName() << endl;

	//				getline(*curFile, tempStr, ',');
	//				getline(*curFile, tempStr, ',');

	//				// add the number of wins to the total number of wins. 
	//				// also add to corresponding weapon. 
	//				(*gameModes[i])[j].setWins(stoi(tempStr));
	//				cout << "wins: " << (*gameModes[i])[j].getWins() << endl;
	//				veryTempWeapVec = (*gameModes[i])[j].getWeaponsVector(); // TODO: is this helpful at all???

	//				//veryTempWeapVec[0][0]

	//				// TODO: finish building the rest of a single substring processing. 

	//				getline(*curFile, tempStr, ',');

	//				// add the number of losses to the total number of losses. 
	//				// also add to corresponding weapon. 
	//				(*gameModes[i])[j].setLosses(stoi(tempStr));
	//				cout << "losses: " << (*gameModes[i])[j].getLosses() << endl;



	//				// TODO: GO BACK TO THIS LINE!!!!!
	//				//(*gameModes[i])[j].getWeaponsVector()[0]



	//				// advance the file pointer to the next stage data to be read. may not be needed after the correct solution is found for loading the data. 
	//				getline(*curFile, tempStr, '~');


	//			}

	//		}

	//	}

	//	

	//	cout << "test" << endl;




	//	stageNumber = 0;


	//}









	// compute the total wins, losses, winrate, lossrate, and total games played for all gamemodes for the single user in the Stat object that is inherited by the Tracker object. 
	// loop through all the data to get a large overall total. 

	cout << "testing" << endl;


	// close all of the open files. 
	userData.close();
	stages.close();
	weapons.close();
	data.close();

	turfwar.close();
	clamblitz.close();
	rainmaker.close();
	towercontrol.close();
	splatzone.close();

}

void Tracker::printOverallStats() {


	cout << "Overall Stats: " << endl <<
		"Wins: " << this->getWins() << endl <<
		"Winrate: " << this->computeWinRate() << endl <<
		"Losses: " << this->getLosses() << endl <<
		"Lossrate: " << this->computeLossRate() << endl <<
		"Total Games Played: " << this->computeTotalGamesPlayed() << endl << endl;


}


Tracker::~Tracker() {


}

void Tracker::loadUserData() {
	// open the UserData.csv file, load the data, then clode the file. 



}

void Tracker::storeAllData() {
	// this function will take all the data in the structures and vectors and write them to the text files. 

	// TODO: this is not finished at all!!!

	vector<Weapon>::iterator weapPtr; // use this iterator to traverse the vector to store the data to the text files.

	//front of vector relates to the top of the stages list. 


}

void Tracker::printTitle() {


	cout << "   _____       _       _    _____ _        _        " << endl;
	cout << "  / ____|     | |     | |  / ____| |      | |       " << endl;
	cout << " | (___  _ __ | | __ _| |_| (___ | |_ __ _| |_ ___  " << endl;
	cout << "  \\___ \\| '_ \\| |/ _` | __|\\___ \\| __/ _` | __/\ __| " << endl;
	cout << "  ____) | |_) | | (_| | |_ ____) | || (_| | |_\\__ \\ " << endl;
	cout << " |_____/| .__/|_|\\__,_|\\__|_____/ \\__\\__,_|\\__|___/ " << endl;
	cout << "        | |                                         " << endl;
	cout << "        |_|                                         " << endl;


}

void Tracker::runApp() {

	// this will be the main functionality of the application. 








}