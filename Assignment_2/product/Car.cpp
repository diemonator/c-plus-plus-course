#include "Car.h"
// OK
Car::Car(const string& model, const string& material, int diameter, int nrWheels)
{
	this->model = model;
	for (unsigned int i = 0; i < (unsigned) nrWheels; i++)
	{
		addWheel(diameter,material);
	}
}
// OK
Car::Car(const Car& myCar) : licensePlate(myCar.licensePlate), model(myCar.model)
{
	for (unsigned int i = 0; i < myCar.wheels.size(); i++)
	{
		wheels.push_back(new Wheel(*(myCar.wheels[i])));
	}
}
// OK
Car::~Car()
{
	for (unsigned int i = 0; i < wheels.size(); i++)
	{
		delete wheels[i];
	}
}
// OK
string Car::getModel() const
{
	return model;
}
// OK
void Car::setLicensePlate(const string& license)
{
	if (!license.empty())
		licensePlate = license;
}
// OK
string Car::getLicensePlate() const
{
	return licensePlate;
}
// OK
int Car::getNrWheels() const
{
	return wheels.size();
}
// OK
Wheel* Car::getWheel(int index)
{
	if (index >= 0 && index < getNrWheels())
		return wheels[index];
	return NULL;
}
// OK
void Car::removeWheel(int index)
{
	delete wheels[index];
	wheels.erase(wheels.begin()+index);
}
// OK
void Car::addWheel(int diameter, const string& material)
{
	wheels.push_back(new Wheel(diameter,material));
}
// OK
Car& Car::operator=(const Car& myCar)
{
	if (&myCar == this) return *this;
	licensePlate = myCar.licensePlate;
	model = myCar.model;
	for (unsigned int i = 0; i < wheels.size(); i++)
	{
		delete wheels[i];
	}
	wheels.clear();
	for (unsigned int i = 0; i < myCar.wheels.size(); i++)
	{
		wheels.push_back(new Wheel(*(myCar.wheels[i])));
	}
	return *this;
}
