// team.cpp - function definitons

#include <string>
#include <fstream>
#include "team.h"
#include "player.h"
#include "consts.h"


// constructor

team::team()
{
	player roster[MAX_PLAYERS];
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
	string oneLine;
	int num;
	string numStr;
	string lName;
	string fName;
	int pos;
	int startOuts;
	int startHits;
	int startWalks;
	int startRBIs;
	int lNameIndex = 0;

	rosterIn.open(fileName); 

	// ignore one line of headings
	rosterIn.ignore(200, '\n');

	while (!rosterIn.eof())
	{
		getline(rosterIn, oneLine);
		
		// sample line of text from file:
		// 2        Hoerner   ,     Nico        2           1        1       0      0
		// 
/* I think we don't need to find the fist lette of the last name if we want to 
*	use a specific column for the last name. The data files we have all start the last name 
*   at column 10 (index 9 of the string oneLine).
*   If we do that, we don't need to include a , between the last and first names.
*      How many characters should we set for the max length of the last name? First name?
*      These are design issues we should decide.
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
		
		// create substring of last name
		lName = oneLine.substr(lNameIndex, COMMA_INDEX - lNameIndex);
		// trim the blanks from the right of the last name
		// lName = trim(lName);  // this function is in the boost pack
		
		// find next instance of a number - this will be the player's position
//  The position should be only one digit - do we want to use that as a standard?
		

		// create substr of first name
		// trim blanks from first name


		// find and convert the remaining 4 numbers - hits, outs, walks, and rbis

	}
}

void team::updateStats(string fileUpdate)
{
	ifstream statsIn;
	statsIn.open(fileUpdate);
}

