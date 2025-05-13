//add.cpp

#include <iostream>

using namespace std;

int main()
{
	//declare variables
	int num1;
	int num2;
	int sum;
	
	
	
	//input numbers
	cout << "Enter two whole numbers seperated by a space, enter two zeros to quit: ";
	
	cin >> num1 >> num2;
	
	while (!(num1 == 0 && num2 == 0))
	{
	//calculate
	sum = num1 + num2;
	
	//output
	cout << endl;
	cout << num1 << " + " << num2 << " = " << sum;
	cout << endl << endl;
	
	//input numbers
	cout << "Enter two whole numbers seperated by a space, enter two zeros to quit: ";
	
	cin >> num1 >> num2;
	
}
	return 0;
	
}