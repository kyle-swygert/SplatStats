#include "General.h"
#include "Tracker.h"

/*
Hello and welcome to SplatStats Version 2! 
This will be a redesign of the original concept to hopefully make the project easier to understand and use in the future. 





Created by: Incredibr0
Released: 2018
Published By: Gaht Dahm Phyzicks Studios / Productions
*/



int main(void) {

	/*
	main functionality of SpatStats:

	Input Data
	Edit Data 
	View Data
	Program Settings (change user name, and other small things) 
	Add new weapon
	Add new Stage
	Store all data (executed after each sub-function just for safety) 
	
	*/

	//TODO: when loading the weapons and stages into the program, create and store the abbreviations in the Stage and Weapon objects. number out all of the weapons in a certain weapon type to easily locate a certain weapon. 


	Tracker user;

	user.printTitle();

	user.printStatusLine();

	cout << user.getUserName() << endl;

	Stat userStat(42, 55), second;


	cout << "end of program" << endl << endl;


	system("pause");

	return 0;

	// The Dirty P is the Place for me. 

}