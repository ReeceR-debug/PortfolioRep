//Name.cpp

#include <iostream>
#include <string>
#include <exception>
#include <typeinfo>
using namespace std;

int main()
{
	//declare variables
	string name;

	int com = name.find(",");
	
	
	string last = name.substr(0, com);

	string first = name.substr(com);



	//input numbers
	cout << "Enter your name in the following format (last, first middle) and I will put your last name last:  ";

	cin >> name;


	getline(cin, name);


	//output

	cout << "Your name is: " << first << last;


	//input numbers
	cout << "Enter your name in the following format (last, first middle) and I will put your last name last:  ";

	cin >> name;
	return 0;
}
