#include <iostream>			
#include <fstream>		
#include <random>

using namespace std;

// prototypes
int inputGuess();

const int MIN = 1;
const int MAX = 100;
const int QUIT = 0;

int main()
{
	// declare variables
	int guess;
	int guessCount = 0;
	int ran;

	cout << "I will pick a random number from " << MIN <<  " to " << MAX << ". You guess the number." << endl << "I'll keep track of how many guesses it takes." << endl << endl;


	guess = inputGuess();
	guessCount++;

	random_device seed;
	mt19937_64 gen{ seed() }; // seed the generator
	uniform_int_distribution<> dist{ MIN, MAX }; // set min and max
	ran = dist(gen); // generate number

	

		while (guess != QUIT) {
			
			if (guess != ran) {
				if (guess > ran){
					cout << "Too High" << endl << endl;
				}
				else {
					cout << "Too Low" << endl << endl;
				}

			}
			else {
				cout << "Good Job!" << " It took you " << guessCount << " tries." << endl << endl;
				cout << "we will now start another round of the game.";

				random_device seed;
				mt19937_64 gen{ seed() }; // seed the generator
				uniform_int_distribution<> dist{ MIN, MAX }; // set min and max
				ran = dist(gen); // generate number

				guessCount = 0;
			}

			guess = inputGuess();
			guessCount++;

		}

		cout << "Thanks for playing!";

	

	return 0;
}


int inputGuess() {
	int guess;


	cout << "Enter your guess (" << MIN <<  "-" << MAX << ", or " << QUIT << " to quit): ";
	cin >> guess;

		while (guess != MIN && guess > MAX || guess < QUIT) {
			cout << guess << " is not within " << MIN << "-" << MAX << "" << endl << endl;
			cout << "Enter your guess (" << MIN << "-" << MAX << ", or " << QUIT << " to quit): " << endl;
			cin >> guess;
		}
	

	return guess;
}