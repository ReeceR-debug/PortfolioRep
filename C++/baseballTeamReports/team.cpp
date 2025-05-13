// team.cpp - function definitons

#include <string>
#include <fstream>
#include "team.h"
#include "player.h"
#include "consts.h"
#include "utils.h"


// constructor

team::team()
{
	teamName = "";
}

// overloaded constructor

team::team(string nameIn)
{
	teamName = nameIn;
}

// destructor

team::~team()
{
	// clean up memory
}


string team::getTeamName() const
{
	return teamName;
}


void team::setTeamName(string nameIn)
{
	teamName = nameIn;
}


void team::loadRoster(string fileName)
{
	ifstream rosterIn;
	
	player onePlayer;
	string oneLine;
	int num;
	string numStr;
	string lName;
	string fName;
	positions pos;
	string posStr;
	int startOuts;
	string outStr;
	int startHits;
	string hitStr;
	int startWalks;
	string walkStr;
	int startRBIs;
	string rbiStr;
	int lNameIndex = 0;

	
	int i = 0;

	rosterIn.open(fileName);

	// ignore one line of headings
	rosterIn.ignore(200, '\n');

	while (!rosterIn.eof())
	{
		getline(rosterIn, oneLine);

		// sample line of text from file:
		// 2        Hoerner        Nico        2        1        1       0      0
		// 
/* I think we don't need to find the fist letter of the last name if we want to
*	use a specific column for the last name. The data files we have all start the last name
*   at column 10 (index 9 of the string oneLine).
*   If we do that, we don't need to include a , between the last and first names.
*
*   11 for the max length of the last name
*	11 for first name
*
* */
// find first letter of last name
		for (int i = 0; i < COMMA_INDEX; i++)
		{
			if (isalpha(oneLine[i]))
			{
				lNameIndex = i;
				break;
			}
		}
		// create string of player's number
		numStr = oneLine.substr(0, lNameIndex);
		// trim blanks from right of number - maybe we don't need to trim ???
				// convert numStr to an int
		num = atoi(numStr.c_str());		// atoi requires a "const char[]"
		//    .c_str() converts the string type to an array of chars
		onePlayer.setNumber(num);
		// create substring of last name
		lName = oneLine.substr(lNameIndex, COMMA_INDEX - lNameIndex);
		// trim the blanks from the right of the last name
//		lName = lName.substr(0, lName.find(' '));
		lName = trimRight(lName);
		onePlayer.setLastName(lName);
		// find next instance of a number - this will be the player's position
//  The position should be only one digit 
		posStr = oneLine.substr(36, 2);
		pos = static_cast<positions>(atoi(posStr.c_str()));
		onePlayer.setPosition(pos);
		// create substr of first name
		fName = oneLine.substr(COMMA_INDEX + 5, MAX_NAME_LENGTH);

		// trim blanks from first name
		fName = fName.substr(0, fName.find(' '));
		onePlayer.setFirstName(fName);
		// find and convert the remaining 4 numbers - hits, outs, walks, and rbis
		// numbers can be 3 digits or less
		outStr = oneLine.substr(54, 2);
		startOuts = atoi(outStr.c_str());
		onePlayer.setOuts(startOuts);
		hitStr = oneLine.substr(45, 2);
		startHits = atoi(hitStr.c_str());
		onePlayer.setHits(startHits);
		walkStr = oneLine.substr(62, 2);
		startWalks = atoi(walkStr.c_str());
		onePlayer.setWalks(startWalks);
		rbiStr = oneLine.substr(69, 2);
		startRBIs = atoi(rbiStr.c_str());
		onePlayer.setRBIs(startRBIs);

		roster[i] = onePlayer;
		i++;
	}
}

void team::updateStats(string fileUpdate)
{
	ifstream statsIn;
	statsIn.open(fileUpdate);
}

