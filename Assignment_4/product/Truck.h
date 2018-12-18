#ifndef TRUCK_H_
#define TRUCK_H_

#include<string>
using namespace std;

class Truck
{
	private:
	int* power;
    string model;
    string material;

	public:
	Truck(const string& model, const string& material, int power);

	virtual ~Truck();

	int getPower();

};
#endif