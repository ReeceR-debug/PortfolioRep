// stateAbbreviations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

const int MAX = 10;

int main()
{

	string state[10] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia"};
	string stateAb[10] = { "AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA" };
	string input;
	int foundIndex;
	int type;

//'HI', 'ID', 'IL', 'IN', 'IA', 'KS', 'KY', 'LA',
		//'ME', 'MD', 'MA', 'MI', 'MN', 'MS', 'MO', 'MT', 'NE', 'NV', 'NH', 'NJ', 'NM', 'NY', 'NC', 'ND', 'OH', 'OK', 'OR', 'PA', 'RI', 'SC', 'SD', 'TN', 'TX', 'UT', 'VT', 'VA', 'WA', 'WV', 'WI', 'WY']

	cout << "Please enter the name or abbreveation of a state(Enter QUIT to quit): " << endl << endl;
	getline(cin, input);
	if (input.length() == 2) {

		transform(input.begin(), input.end(), input.begin(),
			::toupper);
	}
	else {
		transform(input.begin(), input.end(), input.begin(),
			::tolower);
		input[0] = toupper(input[0]);
	}

	cout << endl;
	while (input != "Quit") {

		foundIndex = -1;
		type = 0;
		for (int i = 0; i < MAX; i++) {
			if (input == stateAb[i]) {
				type = 1;
				foundIndex = i;
			}

		}
		for (int j = 0; j < MAX; j++) {
			if (input == state[j]) {
				type = 2;
				foundIndex = j;
			}

		}

		switch (type) {


		case 0:
			cout << "There is no state with that name or abbreveation." << endl << endl;
			cout << "Please enter the name or abbreveation of a state(Enter QUIT to quit): " << endl << endl;
			getline(cin, input);
			if (input.length() == 2) {

				transform(input.begin(), input.end(), input.begin(),
					::toupper);
			}
			else {
				transform(input.begin(), input.end(), input.begin(),
					::tolower);
				input[0] = toupper(input[0]);
			}
			break;

		case 1:
				cout << "The full name for " << input << " is " << state[foundIndex] << endl << endl;
				cout << "Please enter the name or abbreveation of a state(Enter QUIT to quit): " << endl << endl;
				getline(cin, input);
				if (input.length() == 2) {

					transform(input.begin(), input.end(), input.begin(),
						::toupper);
				}
				else {
					transform(input.begin(), input.end(), input.begin(),
						::tolower);
					input[0] = toupper(input[0]);
				}
			break;
		case 2:
				cout << "The abbreviation for " << input << " is " << stateAb[foundIndex] << endl << endl;
				cout << "Please enter the name or abbreveation of a state(Enter QUIT to quit): " << endl << endl;
				getline(cin, input);
				if (input.length() == 2) {

					transform(input.begin(), input.end(), input.begin(),
						::toupper);
				}
				else {
					transform(input.begin(), input.end(), input.begin(),
						::tolower);
					input[0] = toupper(input[0]);
				}
			break;
		
		}
	}


	return 0;
}
