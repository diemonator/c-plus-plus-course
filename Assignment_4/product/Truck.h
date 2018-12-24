#ifndef TRUCK_H_
#define TRUCK_H_

#include<string>
#include<iostream>
using namespace std;

class Truck
{
	private:
		int* power;
		string model;
		string material;
	protected:
		bool isDriving;
	public:
		Truck(const string& model, const string& material, int power);
		virtual ~Truck();
		int getPower();
		virtual void currentState();
		void drive();
		void stop();
		virtual bool getDrivingBoolean() = 0;
};
#endif