// baseballTeamReports.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "team.h"

using namespace std;

int main()
{
    team Cubs;
    team Brewers;

    Cubs.loadRoster("data/Cubs.txt");
 //   Brewers.loadRoster("data/Brewers.txt");

    // Cubs.printBatAvgReport("reports\CubsBefore.txt");
    // Brewers.printBatAvgReport("reports\BrewersBefore.txt");

    Cubs.updateStats("data/CubsUpdate.txt");
 //   Brewers.updateStats("data/BrewersUpdate.txt");

    // Cubs.printBatAvgReport("reports\CubsAfter.txt");
    // Brewers.printBatAvgReport("reports\BrewersAfter.txt");

    return 0;
}

