// dateClass.cpp
// holds the definition of the timeType class functions
/************************
5/27/2024
programmer: Reece Reiger
**************************/
#include "dateClass.h"
#include <iostream>

using namespace std;
//constructor
/*
	this function intializes member variables
	date: 5/27/2024
	programmer: Reece Reiger
	parameters:
	- The date will be set to 1/1/2000

	ASSUMES: none
*/
dateClass::dateClass()
{
	mn = 1;
	day = 1;
	yr = 2000;


}

//overload constructor
/*
	this function intializes member variables
	date: 5/27/2024
	programmer: Reece Reiger
	parameters:
	- int mnIn (inital value for mn)
	- int dayIn (inital value for day)
	- string yrIn (inital value for yr)

	ASSUMES: mnIn is between 1 and 12 inclusive
			 dayIn is between 1 and 31 inclusive
			 descIn is any year
*/
dateClass::dateClass(int mnIn, int dayIn, int yrIn)
{
	mn = mnIn;
	day = dayIn;
	yr = yrIn;

}
//destructor
/*
	this function cleans up memory. There is no memory allocated on the fly
		so there is no memory to be released before the varible memory is released.
	date: 5/27/2024
	programmer: Reece Reiger
	parameters: none

	ASSUMES: none
*/
dateClass::~dateClass()
{


}


/*
	this function prints the date in the format mn/day/yr
	date: 5/27/2024
	programmer: Reece Reiger
	parameters: none

	ASSUMES: none
*/
void dateClass::print() const {
	cout << mn << '/';
	if (day < 10)
	{
		cout << '0';
	}
	cout << day << '/' << yr;
}


/*
	this function prints the date in the format mn/day/yr
	date: 5/27/2024
	programmer: Reece Reiger
	parameters: none

	ASSUMES: none
*/
void dateClass::printM() const {
	
	 switch (day) {

	 case 1:
		 cout << "January ";
		 break;
	 case 2:
		 cout << "February ";
		 break;
	 case 3:
		 cout << "March ";
		 break;
	 case 4:
		 cout << "April ";
		 break;
	 case 5:
		 cout << "May ";
		 break;
	 case 6:
		 cout << "June ";
		 break;
	 case 7:
		 cout << "July ";
		 break;
	 case 8:
		 cout << "August ";
		 break;
	 case 9:
		 cout << "September ";
		 break;
	 case 10:
		 cout << "October ";
		 break;
	 case 11:
		 cout << "November ";
		 break;
	 case 12:
		 cout << "December ";
		 break;

}

	if (day < 10)
	{
		cout << '0';
	}

	cout << day << ',' << yr;
}
// get functions
/* programmer: Reece
   date: 5/29/2024
*/
int dateClass::getMn() const
{
	return mn;
}

int dateClass::getDay() const
{
	return day;
}

int dateClass::getYr() const
{
	return yr;
}
// set functions
/* programmer: Reece
   date: 5/29/2024

   These functions are private so they can not be called
	  from outside the class.
*/
void dateClass::setMn(int mnIn)
{
	mn = mnIn;
}

void dateClass::setDay(int mnIn)
{
	day = dayIn;
}

void dateClass::setYr(int mnIn)
{
	yr = yrIn;
}