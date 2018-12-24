#ifndef FLYINGTRUCK_H_
#define FLYINGTRUCK_H_

#include "Airplain.h"
#include "Truck.h"

#include <string>
using namespace std;


class FlyingTruck : public Truck, public Airplain
{
	public:
		FlyingTruck(const string& model, const string& material, int power, int nrOfEngines);
		virtual ~FlyingTruck();
		void currentState() override;
		bool getDrivingBoolean() override;
		bool getFlyingBoolean() override;
};
#endif