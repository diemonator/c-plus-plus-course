#include "Truck.h"

Truck::Truck(const string& model, const string& material, int power) : model(model),material(material)
{
	this->power = new int(power);
	isDriving = false;
}

Truck::~Truck()
{
	delete power;
}

int Truck::getPower()
{
	return *power;
}

void Truck::drive() {
	isDriving = true;
}

void Truck::stop() {
	isDriving = false;
}

void Truck::currentState() {
	if (isDriving) cout << "Truck is driving" << endl;
	else cout << "Truck is in one place" << endl;
}
