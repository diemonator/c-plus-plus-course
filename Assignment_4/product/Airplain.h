#ifndef AIRPLAIN_H_
#define AIRPLAIN_H_

#include <string>
using namespace std;

class Airplain
{
	private:
		bool isFlying;
		int nrOfEngines;
	
    public:
		Airplain(int nrOfEngines);

		virtual ~Airplain();

		void FlysOff();

		void Land();

		int getNrOfEngines() const;
};
#endif