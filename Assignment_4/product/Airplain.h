#ifndef AIRPLAIN_H_
#define AIRPLAIN_H_

#include <string>
#include <iostream>
using namespace std;

class Airplain
{
	private:
		int nrOfEngines;
	protected:
		bool isFlying;
    public:
		Airplain(int nrOfEngines);
		virtual ~Airplain();
		void flysOff();
		void land();
		int getNrOfEngines() const;
		virtual void currentState();
		virtual bool getFlyingBoolean() = 0;
};
#endif