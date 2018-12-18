/*
 * StorablePiggyBank.h
 *
 *  Created on: Aug 31, 2012
 *      Author: Peter Lambooij
 *
 *  Updated on: August, 2016
 *      Author: Jes'us Ravelo
 */

#ifndef STORABLEPIGGYBANK_H_
#define STORABLEPIGGYBANK_H_

#include "PiggyBank.h"

class StorablePiggyBank: public PiggyBank
{
	private:
		static int nrOfObjects;

	public:
		StorablePiggyBank();
		/*	pre :
			post: an object StorablePiggyBank has been created with
			owner, broken and balance identical to the base class
		*/

		StorablePiggyBank(string name);
		/*	pre :
			post: an object StorablePiggyBank has been created with
			owner = name and broken and balance identical to the base class
		*/

		StorablePiggyBank(string name, int amount);
		/*	pre :
			post: an object StorablePiggyBank has been created with
			owner, broken and balance identical to the base class
		*/

		virtual ~StorablePiggyBank();
		/*	pre :
			post: the object of type StorablePiggyBank has been destroyed.
		*/

		bool store(string filename) const;
		/*	pre :
			post: The values of owner, balance and broken are stored in file filename.
		*/

		bool load(string filename);
		/*	pre :
			post: The values of owner, balance and broken are read from file filename.
		*/

		string serialize(void) const;
		/*	pre :
			post: The values of owner, balance and broken are packed in a string.
		*/

		bool deserialize(string stored);
		/*	pre :
			post: The values of owner, balance and broken are unpacked from string stored.
		*/

		static int getNrOfObjects();
		/* pre :
		   post: The number of StoredPiggyBank objects currently in memory is returned.
		*/
};

#endif /* STORABLEPIGGYBANK_H_ */
