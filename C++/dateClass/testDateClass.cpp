// testDateClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
/**********************************************
This program is to test the dateClass class.

date 5/27/2024
programmer: Reece

***********************************************/

#include <iostream>
#include "dateClass.h"

using namespace std;


int main()
{
	dateClass startTime;
	dateClass endTime(10, 3, 2000);
	dateClass copyTime(endTime);

	cout << endl;
	cout << "startTime = ";
	startTime.print();
	cout << endl;
	cout << "endTime = ";
	endTime.print();
	cout << endl;
	cout << "copyTime = ";
	copyTime.print();
	cout << endl << endl;

	cout << endl;
	cout << "startTime = ";
	startTime.printM();
	cout << endl;
	cout << "endTime = ";
	endTime.printM();
	cout << endl;
	cout << "copyTime = ";
	copyTime.printM();
	cout << endl << endl;



	return 0;
}
