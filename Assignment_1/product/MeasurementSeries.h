#ifndef MEASUREMENTSERIES_H
#define MEASUREMENTSERIES_H

#include <string>
#include <iostream>

using namespace std;

const int MaxMeasurementValues = 10;

class MeasurementSeries
{
private:
	string name;
	int count = 0;
	int measurementData[MaxMeasurementValues];
public:
	MeasurementSeries();
	MeasurementSeries(string n);
	string getName() const;
	void setName(string n);
	bool isFull() const;
	void addValue(int value);
	bool valueExists(int value) const;
	int getValue(int index) const;
	void getNrMeasurements(int& number) const;
};
#endif