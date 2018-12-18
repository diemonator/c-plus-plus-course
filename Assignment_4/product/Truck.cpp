#include "Truck.h"

Truck::Truck(const string& model, const string& material, int power) : model(model),material(material)
{
	this->power = new int(power);
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
	if (&myTruck == this) 
    return *this;
}
