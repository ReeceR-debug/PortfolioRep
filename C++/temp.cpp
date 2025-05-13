//add.cpp

#include <iostream>

using namespace std;

int main()
{
	//declare variables
	int num1;

	int sum;
	
	
	
	//input numbers
	cout << "Enter a temperature in Celsius and I will give you it in Fahrenheit: ";
	
	cin >> num1;
	
	while (num1 != 0)
	{
	//calculate
	sum = (9/5.0 * num1) + 32;
	
	//output
	cout << endl;
	cout << num1 << " in celsius is " << sum << " in Fahrenheit";
	cout << endl << endl;
	
	//input numbers
	cout << "Enter a temperature in Celsius and I will give you it in Fahrenheit: ";
	
	cin >> num1;
	
}
	return 0;
	
}