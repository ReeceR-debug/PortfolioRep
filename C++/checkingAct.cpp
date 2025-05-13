

#include <iostream>		// for cin, cout
#include <iomanip>		// for setprecision, setw
#include <fstream>		// for file input and output
#include <string>


using namespace std;

int main()
{

	string 	 let;
	string	bal;
	double	dep = 0;
	double	with = 0;
	double check = 0;
	double prevbal = 0;
	ofstream fileOut;
	ifstream fileIn;


	fileIn.open("bank.txt");


	getline(fileIn, bal, '\n');
	fileIn.close();

	cout << "Enter D for Deposit" << endl
		<< "      C for Check" << endl
		<< "      W for Withdrawal" << endl
		<< "      E for Exit" << endl;



	cout << endl;
	cin >> let;

	double balB = stod(bal);
	prevbal = balB;

	while (let != "E" || "e")
	{




		if (let == "D" || "d")
		{
			cout << "Enter the transaction amount:";
			cin >> dep;
			cout << endl << endl << endl;

			balB = balB + dep;

			cout << "Transaction Type: Deposit" << endl
				<< "Account Balance:" << prevbal << endl
				<< "Transaction Amount:" << dep << endl
				<< "Current Balance:" << balB << endl;

		}
		else if (let == "W" || "w") {
			cout << "Enter the transaction amount:";
			cin >> with;
			cout << endl << endl << endl;

			balB = balB - with;

			cout << "Transaction Type: Withdrawl" << endl
				<< "Account Balance:" << prevbal << endl
				<< "Transaction Amount:" << with << endl
				<< "Current Balance:" << balB << endl;

		}
		else if (let == "C" || "c") {
			cout << "Enter the transaction amount:";
			cin >> check;
			cout << endl << endl << endl;

			balB = balB - check - .1;

			cout << "Transaction Type: Check" << endl
				<< "Account Balance:" << prevbal << endl
				<< "Transaction Amount:" << check << endl
				<< "Check Fee" << check << endl
				<< "Current Balance:" << balB << endl;


		}
		else {

			cout << "Please select one of the specified letters.";

		}

		cout << endl << endl << endl << "Enter D for Deposit" << endl
			<< "      C for Check" << endl
			<< "      W for Withdrawal" << endl
			<< "      C for Exit" << endl;



		cout << endl;
		cin >> let;



	}

	fileOut.open("bank.txt");

	fileOut << fixed;

	fileOut << balB << endl;
	fileOut.close();

	return 0;
}




