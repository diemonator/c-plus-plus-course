#include "MeasurementSeries.h"

MeasurementSeries::MeasurementSeries()
{
	name = "NoName";
}

MeasurementSeries::MeasurementSeries(string n)
{
	setName(n);
}

string MeasurementSeries::getName() const
{
	return name;
}

void MeasurementSeries::setName(string n)
{
	if (!n.empty())
		name = n;
}

bool MeasurementSeries::isFull() const
{
	if (count < MaxMeasurementValues)
		return false;
	else return true;
}

void MeasurementSeries::addValue(int value)
{
	if (!isFull()) 
	{
		measurementData[count++] = value;
	}
}

bool MeasurementSeries::valueExists(int value) const
{
	for (int i = 0; i < count; i++)
	{
		if (measurementData[i] == value)
			return true;
	}
	return false;
}

int MeasurementSeries::getValue(int index) const
{
	if (index >= 0 && index < MaxMeasurementValues)
		return measurementData[index];
	return -1;
}

void MeasurementSeries::getNrMeasurements(int& number) const
{
	number = count;
}
