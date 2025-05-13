/* player.h - This file contains the definition of the player class.
programmer:  Joanie
date:        5/22/24
*/

#pragma once

#include <string>
#include "enums.h"

using namespace std;


class player
{
	public:
		player();	// constructor
		player(int numIn, string firstIn, string lastIn, positions posIn);
		~player();	// destructor

		// get functions
		int getNumber() const;
		string getFirstName() const;
		string getLastName() const;
		positions getPosition() const;
		int getHits() const;
		int getOuts() const;
		int getWalks() const;
		int getRBIs() const;

		// set functions
		void setNumber(int numIn);
		void setFirstName(string firstIn);
		void setLastName(string lastIn);
		void setPosition(positions posIn);
		void setHits(int hitsIn);
		void setOuts(int outsIn);
		void setWalks(int walksIn);
		void setRBIs(int RBIsIn);

		// print functions
		void printPlayerNumLastBatAvgMultiLine() const;
		void printPlayerNumLastBatAvgSingleLine() const;
		void printPlayerNumFirstLastPositionHitsOutsWalksRBIMultiLine() const;
		void printPlayerNumFirstLastPositionHitsOutsWalksRBISingleLine() const;

		//update stats
		void updateStats(int hitsIn, int outsIn, int walksIn, int RBIsIn);

		//calculate batting avg
		double calcBatAvg() const;


	private:
		int number;
		string firstName;
		string lastName;
		positions position;
		int hits;
		int outs;
		int walks;
		int RBIs;

	
		

		//update stats
		void updateHits(int hitsIn);
		void updateOuts(int outsIn);
		void updateWalks(int walksIn);
		void updateRBIs(int RBIsIn);
};


