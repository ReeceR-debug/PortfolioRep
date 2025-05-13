// testPlayer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* This file tests that the member functions of player class work properly.
 programmer: Joanie
 date: 5/22/24
 */



#include <iostream>
#include "player.h"
#include "enums.h"

using namespace std;

int main()
{
    int addedHits;
    player onePlayer;
    player anotherPlayer(10, "Mickey", "Mouse", CATCHER);

    cout << endl << "end" << endl;

    onePlayer.printPlayer();
    anotherPlayer.printPlayer();

    cout << "hits: " << anotherPlayer.getHits() << endl << endl;
    cout << "Enter added hits: ";
    cin >> addedHits;
    anotherPlayer.updateHits(addedHits);
    cout << "hits: " << anotherPlayer.getHits();


    anotherPlayer.printPlayer();

    return 0;
}

