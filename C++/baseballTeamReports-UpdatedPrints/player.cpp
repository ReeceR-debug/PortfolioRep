/* player.cpp - This file holds the function definitions of the member 
                 functions of the player class.
   programmer: Joanie
   date: 5/22/24

*/
#include <iostream>
#include "player.h"
#include "enums.h"
#include <string>

using namespace std;

//array for printing
/* programmer: Reece
   date: 5/22/24
*/
string posName[] = { "PITCHER", "FIRST", "SECOND", "THIRD", "CATCHER",
				 "CENTER", "SHORTSTOP", "LEFT", "RIGHT" };

// constructor
/* programmer: Joanie
   date: 5/22/24
*/
player::player()
{
	number = 0;
	firstName = "";
	lastName = "";
	position = FIRST;
	hits = 0;
	outs = 0;
	walks = 0;
	RBIs = 0;
}

// overloaded constructor
/* programmer: Joanie
   date: 5/22/24
   parameters:
      numIn - value for number
      firstIn - value for firstName
      lastIn - value for lastName
      posIn - value for position

	  other member variables set to 0:
        hits - set to 0
	    outs - set to 0
	    walks - set to 0
	    RBIs - set to 0
*/
player::player(int numIn, string firstIn, string lastIn, positions posIn)
{
	number = numIn;
	firstName = firstIn;
	lastName = lastIn;
	position = posIn;
	hits = 0;
	outs = 0;
	walks = 0;
	RBIs = 0;
}


// destructor
/* programmer: Joanie
   date: 5/22/24
*/
player::~player()
{
	// clean up of memory allocated on the fly
}


// get functions 
/* programmer: Reece Reiger
   date: 5/28/24
*/
int player::getNumber() const
{
	return number;
}

string player::getFirstName() const
{
	return firstName;
}

string player::getLastName() const
{
	return lastName;
}

positions player::getPosition() const
{
	return position;
}

int player::getHits() const 
{
	return hits;
}

int player::getOuts() const
{
	return outs;
}

int player::getWalks() const
{
	return walks;
}

int player::getRBIs() const
{
	return RBIs;
}


// set functions
/* programmer: Reece Reiger
   date: 5/28/24

   These functions are private so they can not be called 
      from outside the class.
*/
void player::setNumber(int numIn)
{
	number = numIn;
}

void player::setFirstName(string firstIn)
{
	firstName = firstIn;
}

void player::setLastName(string lastIn)
{
	lastName = lastIn;
}

void player::setPosition(positions posIn)
{
	position = posIn;
}

void player::setHits(int hitsIn)
{
	hits = hitsIn;
}

void player::setOuts(int outsIn)
{
	outs = outsIn;
}

void player::setWalks(int walksIn)
{
	walks = walksIn;
}

void player::setRBIs(int RBIsIn)
{
	RBIs = RBIsIn;
}


/* programmer: Reece Reiger
   date: 5/28/24

   This is a print function
*/

void player::printPlayer() const
{
	cout << "Player number is " << number << " and name is " << firstName << lastName << endl;
	cout << "Position - Hits - Outs - Walks - RBIs" << endl;
	cout << posName[position] << "     " << hits << "      " << outs << "      " << walks << "       " << RBIs << endl << endl;
}


// set functions
/* programmer: Reece Reiger
   date: 5/28/24
  
  This is the function to update stats.
*/
void player::updateHits(int hitsIn)
{
	hits += hitsIn;
}

void player::updateOuts(int outsIn)
{
	outs += outsIn;
}

void player::updateWalks(int walksIn)
{
	walks += walksIn;
}

void player::updateRBIs(int RBIsIn)
{
	RBIs += RBIsIn;
}

void player::updateStats(int hitsIn, int outsIn, int walksIn, int RBIsIn) 
{
	updateHits(hitsIn);
	updateOuts(outsIn);
	updateWalks(walksIn);
	updateRBIs(RBIsIn);
}