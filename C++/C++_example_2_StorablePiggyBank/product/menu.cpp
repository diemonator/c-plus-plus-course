//==========================================s==================================
// Name        : menu.cpp
// Author      : Peter Lambooij
//               Jes'us Ravelo (slightly modified, August 2016,
//                              mainly to make functions smaller)
// Version     :
// Copyright   : copyright Peter Lambooij
// Description : Example code C++ week 1
//
//				 Chapter 3 van the study book (Gaddis et al.):
//				 	 cin, cout, getline, cin.getc(), cin.ignore(), endl
//
//				 Chapter 7 of the book :
//					 Classes with constructor and member functions
//					 (properties like in C# do not exist in C++,
//					  and there is always a split-up in header and source file)
//
//				 Two different ways of parameter passing are shown:
//				 "call-by-value" (C# style, as taught in PCSx courses) and "call-by-reference".
//============================================================================

#include "StorablePiggyBank.h"
#include <iostream>

#include <string>    // C++ has a so-called string class that resembles the C# String/string classes.
using namespace std; // These two lines (#include and using) are necessary to be able to use the C++ string class.

void showMenu( void )
{
	cout << ("\n\nPIGGYBANK MENU");
	cout << ("\n===========================");
	cout << ("\n[1] Show owner name.");
	cout << ("\n[2] Change owner name.");
	cout << ("\n[3] Deposit money in PiggyBank.");
	cout << ("\n[4] Test if PiggyBank is Broken.");
	cout << ("\n[5] Break PiggyBank and return money");
	cout << ("\n[6] Save the PiggyBank state in a file.");
	cout << ("\n[7] Load the PiggyBank state from a file.");
	cout << ("\n[8] Show number of created PiggyBanks.");
	cout << ("\n[9] Exit.");
	cout << ("\n\nChoice : ");
}


void option1(const StorablePiggyBank &aStorablePiggyBank)
{
	cout << aStorablePiggyBank.getOwnerName() << endl;
}


void option2(StorablePiggyBank &aStorablePiggyBank)
{
	string name;

	cout << "Please enter new owner name: ";
	getline(cin, name);                              // C++ style i/o: chapter 3 in book
	aStorablePiggyBank.setOwnerName(name);
}


void option3(StorablePiggyBank &aStorablePiggyBank)
{
	int amount;

	if (aStorablePiggyBank.isBroken())
		cout << "You cannot deposit money in a broken PiggyBank!" << endl;
	else
	{
		cout << "Please enter the amount you want to deposit: ";
		cin >> amount;
		cin.ignore();     // C++ style i/o: chapter 3 in book
		aStorablePiggyBank.depositMoney(amount);
	}
}


void option4(const StorablePiggyBank &aStorablePiggyBank)
{
	if (aStorablePiggyBank.isBroken())
		cout << "The piggybank is broken." << endl;
	else
		cout << "The piggybank is still intact." << endl;
}


void option5(StorablePiggyBank &aStorablePiggyBank)
{
	int amount;

	if (aStorablePiggyBank.isBroken())
		cout << "A piggybank cannot be smashed twice!" << endl;
	else
	{
		amount = aStorablePiggyBank.smash();
		cout << "Breaking the PiggyBank gave us 300 pieces of plastic and: " << amount << " Euro" << endl;
	}
}


void option6(const StorablePiggyBank &aStorablePiggyBank)
{
	string name;
	bool success;

	cout << "Please enter file name: ";
	cin >> name;
	cin.ignore(); // C++ style i/o: chapter 3 in book
	success = aStorablePiggyBank.store(name);
	if (success)
	{
		cout << "Piggybank state was stored successfully." << endl;
	}
	else
	{
		cout << "Failed to store piggybank state." << endl;
	}
}


void option7(StorablePiggyBank &aStorablePiggyBank)
{
	string name;
	bool success;

	cout << "Please enter file name: ";
	cin >> name;
	cin.ignore();
	success = aStorablePiggyBank.load(name);
	if (success)
	{
		cout << "Piggybank state was loaded successfully." << endl;
	}
	else
	{
		cout << "Failed to load piggybank state." << endl;
	}
}


void option8()
{
	// static member functions are called like this: classname::functionname()
	cout << StorablePiggyBank::getNrOfObjects() << " piggybanks have been created" << endl;
}


int main( void )
{
	bool quit = false;
	char choice;

	StorablePiggyBank myStorablePiggyBank("Bill Gates");

	while (!quit)
	{
		showMenu();
		cin.get(choice);    // C++ style i/o: chapter 3 in book
        cin.ignore();       // C++ style i/o: chapter 3 in book

		switch (choice)
		{
			case '1' :
				option1(myStorablePiggyBank);
				break;
			case '2' :
				option2(myStorablePiggyBank);
				break;
			case '3' :
				option3(myStorablePiggyBank);
				break;
			case '4' :
				option4(myStorablePiggyBank);
			    break;
			case '5' :
				option5(myStorablePiggyBank);
			    break;
			case '6' :
				option6(myStorablePiggyBank);
				break;
			case '7' :
				option7(myStorablePiggyBank);
				break;
			case '8' :
				option8();
				break;
			case '9':
				quit = true;
				break;
			default:
				cout << "\n\nInvalid choice: \'" << choice << "\'";
				break;
		}
	}

	return 0;
}
