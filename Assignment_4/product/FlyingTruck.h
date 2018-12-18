#ifndef FLYINGTRUCK_H_
#define FLYINGTRUCK_H_

#include "Airplain.h"
#include "Truck.h"

#include <string>
using namespace std;


class FlyingTruck : public Airplain, public Truck
{
	public:
		FlyingTruck();
		virtual ~FlyingTruck();
};
#endif