//circle.cpp

#include <iostream>

using namespace std;
const double PI = 3.141592653;
int main()
{
	//declare variables
	int radius;

	int area;
	
	int diameter;
	
	int circumference;
	

	
	//input numbers
	cout << "Enter the radius of a circle and I will give you the area, circumference, and the diameter of the circle. Enter 0 to quit:  ";
	
	cin >> radius;
	
	while (radius != 0)
	{
	//calculate
	area = PI * (radius * radius);
	
	circumference = 2 * PI * radius;
	
	diameter = radius * 2;
	
	//output

	cout << "The area is " << area << ", the circumference is " << circumference << ", and the diameter of the circle is " << diameter << ".";

	
	//input numbers
	cout << "Enter the radius of a circle and I will give you the area, circumference, and the diameter of the circle. Enter 0 to quit:  ";
	
	cin >> radius;
	
}
	return 0;
	
}