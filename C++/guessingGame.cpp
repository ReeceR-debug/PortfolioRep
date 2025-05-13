// guessingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>;
using namespace std;

int main() {
	int guess;
	int randNum;
	int numGuesses;
	//unsigned seed;


	numGuesses = 0;
	// generate random number
	//unsigned seed = time(0);
	//srand(seed);
	randNum = rand() % 101;
	do {
		cout << "Can you guess the random number?(1-100, 0 to quit): " << endl;
		cin >> guess;
		if (guess > 100 || guess < 0) {
			cout << "Error" << endl;
		}
	} while (guess > 100 || guess < 0);

	while (guess != 0) {
		if (guess != randNum) {
			if (guess > randNum) {
				cout << "Too High!" << endl;
				numGuesses++;
			}
			else {
				cout << "Too Low!" << endl;
				numGuesses++;
			}
		}
		else {
			cout << "It took you " << numGuesses << " tries!" << endl;

			// make new randNum
			//unsigned seed = time(0);
			//srand(seed);
			numGuesses = 0;
			randNum = rand() % 101;
			cout << "rannum is " << randNum;
		}
		do {
			cout << "Can you guess the random number?(1-100, 0 to quit): " << endl;
			cin >> guess;
			if (guess > 100 || guess < 0) {
				cout << "Error" << endl;
			}
		} while (guess > 100 || guess < 0);
		
	}




	cout << "Goodbye!" << endl;


	return 0;
}
