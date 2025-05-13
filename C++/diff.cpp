// diff.cpp
// Reece
// 2/21/2024

#include <iostream>		
#include <iomanip>		
#include <fstream>		
#include <string>

using namespace std;


int main()
{
	// declare variables
	int 	 tempNum;
	double 	 temp;
	double 	 prevTemp;
	double 	 average;
	double 	 diff;
	double 	 total;
	ifstream fileIn;
	ofstream fileOut;

	tempNum = 0;
	temp = 0;
	prevTemp = 0;
	average = 0;
	diff = 0;
	total = 0;


	fileIn.open("numIn.txt");
	fileOut.open("tempReport.txt");

	

	fileOut << "Temperature    Difference" << endl;

	cout << fixed;
	fileOut << fixed;

	// prompt and read in empID
	cout << endl;
	cout << "Going through temperatures in numIn.dat";

	while (tempNum<12)
	{
		
		//math
	
		fileIn >> temp;
		diff = temp - prevTemp;
		total = total + temp;
		prevTemp = temp;
		if (tempNum >= 1) {
			fileOut << setw(3) << setprecision(1) << temp << "			" << diff;
			fileOut << endl; 
		}
		else {
			fileOut << setw(3) << setprecision(1) << temp;
			fileOut << endl; 
		}
		tempNum++;


		

	}
	average = total / 12;
	cout << endl;
	cout << endl;
	cout << setw(3) << setprecision(1) << "The average of all of the temperatures is: " << average;
	cout << endl;
	cout << endl;
	return 0;
}




