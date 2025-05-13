// inputTime.cpp
// Reece
// 3/26/24


#include <iostream>
#include <string>

using namespace std;

// prototypes
void inputTime(int& hr, int& min, string& desc);
bool isValidTime(int hr, int min, string desc);

int main()
{
	int hour;
	int minutes;
	string desc;

	inputTime(hour, minutes, desc);

	// print time
	cout << endl;
	cout << hour << ':';
	if (minutes <= 9)
		cout << '0';
	cout << minutes << desc;
	cout << endl << endl;

	return 0;
}


void inputTime(int& hr, int& min, string& desc)
{
	bool validTime = true;

	do
	{
		cout << "Enter time in the format \"hh:mmAM\": ";
		cin >> hr;
		cin.ignore(1);
		cin >> min >> desc;

		validTime = isValidTime(hr, min, desc);


	} while (!validTime);

}


bool isValidTime(int hr, int min, string desc)
{
	bool valid = true;
	if (!(hr > 0 && hr < 13)) {

		valid = false;

	}

	if (!(min >= 0 && min < 60)) {

		valid = false;

	}

	if (!(desc == "AM" || desc == "PM" || desc == "am" || desc == "pm")) {

		valid = false;

	}


	return valid;
}