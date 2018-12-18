/*
 * PiggyBank.cpp
 *
 *  Created on: Aug 31, 2012
 *  Author: Peter Lambooij
 *
 *  Updated on: August, 2016
 *  Author: Jes'us Ravelo
 */


#include "PiggyBank.h"
#include <iostream>
using namespace std;


//---------------------------------------------------------------------------

// the default constructor, without parameters, implemented by every c++ class

PiggyBank::PiggyBank(void)
    : owner("")         // initializer list. As with C#, this "code" is executed before the code in the body
    , balance(0)        // please keep in mind that these members are *always* initialised in the order of appearance
    , broken(false)     // in the header file, so please keep that order the same as here!
{
}

PiggyBank::PiggyBank(string name)
    : owner(name)
    , balance(0)
    , broken(false)
{
}

PiggyBank::PiggyBank(string name, int startBalance)
{
	// an alternative for initializer lists (see above): assign values to class data members attributes in the body
	owner = name;
	balance = startBalance;
	broken = false;
}

PiggyBank::~PiggyBank(void)
{
	// the so-called destructor contains code that needs to be executed
	// just before an object is destroyed (e.g. check if a file has been closed properly)
	// we will come back to destructors in a later lesson
	cout << "PiggyBank destroyed" << endl;
}

string PiggyBank::getOwnerName() const
{
	return owner;
}

void PiggyBank::setOwnerName(string name)
{
	owner = name;
}

bool PiggyBank::isBroken() const
{
	return broken;
}

int PiggyBank::getBalance() const
{
    return balance;
}

void PiggyBank::depositMoney(int amount)
{
	if (!isBroken())
    {
        balance += amount;
    }
}

int PiggyBank::smash()
{
    int currentBalance = balance;

    balance = 0;
    broken = true;

    return currentBalance;
}
