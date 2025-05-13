//cube.cpp

#include <iostream>

using namespace std;

int main()
{
	//declare variables
	int length;

	int area;
	
	int volume;
	
	int surface;
	
	
	
	//input numbers
	cout << "Enter the length of one edge of a cube and I will give you the area of one side, surface area, and the volume. Enter 0 to quit:  ";
	
	cin >> length;
	
	while (length != 0)
	{
	//calculate
	area = length * length;
	
	surface = area * 6;
	
	volume = length * length * length;
	
	//output

	cout << "The area of one side is " << area << ", the surface area is " << surface << ", and the volume of the cude is " << volume << ".";

	
	//input numbers
	cout << " Enter the length of one edge of a cube and I will give you the area of one side, surface area, and the volume. Enter 0 to quit:  ";
	
	cin >> length;
	
}
	return 0;
	
}