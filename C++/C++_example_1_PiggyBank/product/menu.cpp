//============================================================================
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

#include "PiggyBank.h"
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
	cout << ("\n[4] Show PiggyBank balance.");
	cout << ("\n[5] Test if PiggyBank is Broken.");
	cout << ("\n[6] Break PiggyBank and return money");
	cout << ("\n[7] Quit.");
	cout <<  ("\n\nChoice : ");
}


void option1(const PiggyBank &aPiggyBank)
{
	cout << aPiggyBank.getOwnerName() << endl;
}


void option2(PiggyBank &aPiggyBank)
{
	string name;

	cout << "Please enter new owner name: ";
	getline(cin, name);                              // C++ style i/o: chapter 3 in book
	aPiggyBank.setOwnerName(name);
}


void option3(PiggyBank &aPiggyBank)
{
	int amount;

	if (aPiggyBank.isBroken())
		cout << "You cannot deposit money in a broken PiggyBank!" << endl;
	else
	{
		cout << "Please enter the amount you want to deposit: ";
		cin >> amount;
		cin.ignore();     // C++ style i/o: chapter 3 in book
		aPiggyBank.depositMoney(amount);
	}
}


void option4(const PiggyBank &aPiggyBank)
{
	if (aPiggyBank.isBroken())
		cout << "A broken PiggyBank can no longer contain money" << endl;
	else
		cout << "PiggyBank balance is: " << aPiggyBank.getBalance() << " Euro" << endl;
}


void option5(const PiggyBank &aPiggyBank)
{
	if (aPiggyBank.isBroken())
		cout << "PiggyBank is dead-ish" << endl;
	else
		cout << "PiggyBank is alive and ready to store your money :)" << endl;
}


void option6(PiggyBank &aPiggyBank)
{
	int amount;

	if (aPiggyBank.isBroken())
		cout << "How dare you smashing an already tormented PiggyBank" << endl;
	else
	{
		amount = aPiggyBank.smash();
		cout << "Breaking the PiggyBank gave us 300 pieces of plastic and: " << amount << " Euro" << endl;
	}
}


int main( void )
{
	bool quit = false;
	char choice;

	PiggyBank myPiggyBank("Hagrid");

	while (!quit)
	{
		showMenu();
		cin.get(choice);    // C++ style i/o: chapter 3 in book
        cin.ignore();       // C++ style i/o: chapter 3 in book

		switch (choice)
		{
			case '1' :
				option1(myPiggyBank);
				break;
			case '2' :
				option2(myPiggyBank);
				break;
			case '3' :
				option3(myPiggyBank);
				break;
			case '4' :
				option4(myPiggyBank);
			    break;
			case '5' :
				option5(myPiggyBank);
			    break;
			case '6' :
				option6(myPiggyBank);
				break;
			case '7' :
				quit = true;
				break;
			default:
				cout << "\n\nI am terribly sorry for not understanding choice \'" << choice << "\'";
				break;
		}
	}

	return 0;
}
