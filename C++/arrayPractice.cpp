// arrayPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int MAX = 5;
//prototypes
void fillIntArray(int arrayToFill[], int size);
void printIntArray(int arrayToPrint[], int size);
int findStringInArray(string toFind, string array[], int size);

int main()
{

	int count[MAX];
	string animals[] = { "cat", "dog", "horse", "moose", "bird" };
	string animalName;
	int foundIndex;
	int i;

	fillIntArray(count, MAX);

	cout << endl;
	printIntArray(count, MAX);
	cout << endl << endl;



	cout << "the coices are cat, dog, horse, moose, and bird." << endl;
	cout << "Enter an animal name: ";
	cin >> animalName;

	//find animal in array
	foundIndex = findStringInArray(animalName, animals, MAX);

	if (foundIndex == -1)
	{
		cout << "There are no " << animalName << "s.";
		cout << endl;
	}
	else
	{
		if (count[foundIndex] == 1)
		{
			cout << "There is " << count[foundIndex] << " " << animalName << ".";
			cout << endl;
		}
		else
		{
			cout << "There are " << count[foundIndex] << " " << animalName << "s.";
			cout << endl;
		}
	}

	return 0;
}


void fillIntArray(int arrayToFill[], int size)
{
	int i;
	cout << "Enter " << size << " whole numbers seperated by spaces: ";

	for (i = 0; i < size; i++)
	{
		cin >> arrayToFill[i];
	}
}

void printIntArray(int arrayToPrint[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		cout << arrayToPrint[i] << ' ';
	}
}

int findStringInArray(string toFind, string array[], int size)
{
	int foundIndex = -1;
	int i;

	for (i = 0; i < size; i++)
	{
		if (toFind == array[i])
		{
			foundIndex = 1;
		}
	}


	return foundIndex;
}