//dateClass.h
//this file holds the definition of the timeType class
/*******************************
5/27/2024
programmer: Reece Reiger
*******************************/
#pragma once
#include<string>

using namespace std;

class dateClass {

public:
	dateClass();         //constructor
	dateClass(int mnIn, int dayIn, int yrIn); //overloaded constructor
	~dateClass(); //deconstructor
	int getMn() const;
	int getDay() const;
	int getYr() const;

	void print() const; //print
	void printM() const; //print with word month

private:
	int mn;
	int day;
	int yr;
	void getMn(int mnIn);
	void getDay(int dayIn);
	void getYr(int yrIn);

};




