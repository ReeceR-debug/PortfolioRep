//removeLetters.cpp

#include <iostream>
#include <string>

using namespace std;

int main()

{
	string strIn;
	char letterToRemove;
	int foundIndex;
	string tempStr1;
	string tempStr2;

	
	cout << "Enter a sentence: ";
	getline(cin, strIn);
	
	cout << "What letter do you want to remove? ";
	cin.get(letterToRemove);
	
	foundIndex = strIn.find(letterToRemove);
	
	while ( foundIndex != -1)
	{
		tempStr1 = strIn.substr(0, foundIndex);
		tempStr2 = strIn.substr(foundIndex + 1);
		strIn = tempStr1 + tempStr2;
		
		foundIndex = strIn.find(letterToRemove);
	}
	
	cout << endl;
	cout << strIn;
	cout << endl << endl;
		





	return 0;
	}