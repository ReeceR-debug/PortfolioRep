//payroll.cpp
//Reece Reiger
//2/6/2024

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const double fullHours = 40.0;
const double overTime = 1.5;


int main()

{
	//declare variables
	int       empID;
	double    hours;
	double    payrate;
	double    pay;
	ofstream  fileOut;
	
	
	fileOut.open("payrollReport.txt", ios::app);
	
	
	
	cout << fixed;
	
	fileOut << fixed;
	
	
	fileOut << "Employee	Hours	  Pay     Pay" << endl
			<< "ID          Worked    Rate" << endl << endl;
	//prompt and read in empID
	
	cout<< "Please enter your employee ID: ";
	cin >> empID;
	
	
	
	while (empID !=0)
	{
		//prompt and read in hours
		cout<< "Please enter the ammount of hours worked: ";
	cin >> hours;
		
		
		//prompt and read in hourly wage
		cout<< "Please enter your hourly pay: ";
	cin >> payrate;
		
		
		//calculate pay
		
		
		if (hours > fullHours)
		{
			pay = (fullHours * payrate) + ((hours - fullHours) * (payrate * overTime));
		}
		else
		{
			pay = payrate * hours;
		}


		//print
	cout << endl;
	
	
	cout << setw(5) << empID 
		 << setw(10) << setprecision(1) << hours 
		 << setw(10) << setprecision(2) << payrate 
		 << setw(10) << setprecision(2) << pay;
		 
	cout << endl << endl;
	
	
	//for fileOut

	fileOut << setw(5) << empID 
			<< setw(10) << setprecision(1) << hours 
			<< setw(10) << setprecision(2) << payrate 
			<< setw(10) << setprecision(2) << pay << endl;

	
	
	
	
	
	
		//prompt and read in empID
	
	cout<< "Please enter you employee ID: ";
	cin >> empID;
	

	
	}






	return 0;
	}