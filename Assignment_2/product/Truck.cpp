#include "Truck.h"

Truck::Truck(const string& model, const string& material, int diameter, int nrWheels, int power) : Car(model,material,diameter,nrWheels)
{
	this->power = new int(power);
}

Truck::Truck(const Truck& myTruck) : Car(myTruck)
{
	this->power = new int(*myTruck.power);
}

Truck::~Truck()
{
	delete power;
}
// OK
int Truck::getPower()
{
	return *power;
}
// OK
Truck& Truck::operator=(const Truck& myTruck)
{
	if (&myTruck == this) return *this;
	Car::operator=(myTruck);
	return *this;
}
