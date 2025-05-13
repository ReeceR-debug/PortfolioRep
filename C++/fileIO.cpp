//removeLetters.cpp

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()

{
	string strIn;
	char letterToRemove;
	int foundIndex;
	string tempStr1;
	string tempStr2;
	ifstream fileIn;
	string originalStr;
	
	fileIn.open("sentance.dat");
	
	getline(fileIn, strIn);
	
	cout << "What letter do you want to remove? ";
	cin.get(letterToRemove);
	
	originalStr = strIn;
	foundIndex = strIn.find(letterToRemove);
	
	while ( foundIndex != -1)
	{
		tempStr1 = strIn.substr(0, foundIndex);
		tempStr2 = strIn.substr(foundIndex + 1);
		strIn = tempStr1 + tempStr2;
		
		foundIndex = strIn.find(letterToRemove);
	}
	
	cout << endl;
	cout << "Original Sentance: " << originalStr;
	cout << endl;
	cout << "Edited Sentance: " << strIn;
	cout << endl << endl;
		





	return 0;
	}