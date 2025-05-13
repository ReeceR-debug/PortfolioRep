// team.h- header file from team.cpp

#pragma once

#include <string>
#include "player.h"

using namespace std;

class team 
{
	public:
		team();	  // constructor		
		team(string nameIn);
		~team();  // destructor	

		void loadRoster(string fileName);
		void updateStats(string fileUpdate);
		void saveStats();

		string getTeamName() const;

	private:
		// member variables
		player roster[20];
		string teamName;

		void setTeamName(string nameIn);
		
};