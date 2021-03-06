/*
 * PiggyBank.h
 *
 *  Created on: Jul 14, 2012
 *      Author: P. Lambooij
 *
 *  Updated on: August, 2016
 *      Author: J. Ravelo
 */

#ifndef PIGGYBANK_H_
#define PIGGYBANK_H_

#include <string>
using namespace std;

class PiggyBank
{
	private:
		string owner;        // PiggyBank owner
		int balance;         // Current balance in PiggyBank
		bool broken;         // true if PiggyBank is broken, else false

	public:
		PiggyBank(void);
		/*	pre :
			post: a PiggyBank object is created, owner equals ""
			broken is false, balance is 0
		*/

		PiggyBank(string name);
		/*	pre :
			post: a PiggyBank object is created, owner equals name
			broken is false, balance is 0
		*/

		PiggyBank(string name, int startBalance);
		/*	pre :
			post: a PiggyBank object is created, owner equals name
			broken is false, balance is startBalance
		*/

		~PiggyBank(void);
		/*	pre :
			post: the object of type PiggyBank has been destroyed.
		*/

		string getOwnerName() const;
		/*	pre :  -
			post: return the PiggyBank owner's name
		*/

		void setOwnerName(string name);
		/*	pre :
			post: the PiggyBank owner's name is set to name
		*/

		bool isBroken() const;
		/*	pre :
			post: if PiggyBank is broken
			then return true
			else return false
		*/

		int getBalance() const;
		/*	pre : PiggyBank is not broken
			post: balance is returned
		*/

		void depositMoney(int amount);
		/*	pre :
			post: If PiggyBank is not broken
			then amount is added to PiggyBank balance
			else nothing has changed
		*/

		int smash();
		/*	pre : PiggyBank is not broken
			post: return current balance and PiggyBank is broken
		*/
};

#endif /* PIGGYBANK_H_ */
