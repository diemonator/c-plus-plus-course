#include <iostream>
#include "MeasurementSeries.h"

void giveOptions();
void optionOne(MeasurementSeries &series);
void optionTwo(MeasurementSeries &series);
void optionThree(MeasurementSeries &series);
void optionFour(MeasurementSeries &series);
void optionFive(MeasurementSeries &series);
void optionSix(MeasurementSeries &series);
void optionSeven(MeasurementSeries &series);

int main(void)
{
	MeasurementSeries series;
	int choice = 0;
	giveOptions();
	while (choice != 8)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			optionOne(series);
			break;
		case 2:
			optionTwo(series);
			break;
		case 3:
			optionThree(series);
			break;
		case 4:
			optionFour(series);
			break;
		case 5:
			optionFive(series);
			break;
		case 6:
			optionSix(series);
			break;
		case 7:
			optionSeven(series);
			break;
		}
		cout << endl;
		giveOptions();
	}
	cout << endl;
}

void giveOptions()
{
	cout << "1) Show All Values." << endl;
	cout << "2) Add A Mesurment Value." << endl;
	cout << "3) Check If Another Value Can Be Added." << endl;
	cout << "4) Show How Often A Mesurment Value Is Stored." << endl;
	cout << "5) Show Mesurment Series' Name." << endl;
	cout << "6) Change The Mesurment Series' Name." << endl;
	cout << "7) Check For Mesurment Value." << endl;
	cout << "8) Quit" << endl << endl;
	cout << "Type option now: ";
}

void optionOne(MeasurementSeries &series)
{
	int lenght;
	series.getNrMeasurements(lenght);
	for (int i = 0; i < lenght; i++)
	{
		cout << endl << "Index: " << i << " Tons: " << series.getValue(i);
	}
	cout << endl;
}

void optionTwo(MeasurementSeries &series)
{
	int value;
	cout << "Type to add a value: ";
	cin >> value;
	series.addValue(value);
}

void optionThree(MeasurementSeries &series)
{
	string text;
	if (series.isFull()) text = "\nThe data capacity is full!";
	else text = "\nThere is still space!";
	cout << text << endl;
}

void optionFour(MeasurementSeries &series)
{
	int value, lenght, count = 0;
	cout << "Enter value: ";
	cin >> value;
	series.getNrMeasurements(lenght);
	for (int i = 0; i < lenght; i++)
	{
		if (series.getValue(i) == value)
			count++;
	}
	cout << "Result is: " << count << endl;
}

void optionFive(MeasurementSeries &series)
{
	cout << "\nThe name of the series is: " << series.getName() << endl;
}

void optionSix(MeasurementSeries &series)
{
	string name;
	cout << "\nChange Measurement Series Name with: ";
	cin >> name;
	series.setName(name);
}

void optionSeven(MeasurementSeries &series)
{
	int value;
	string text;
	cout << "Type a data value to check if it is stored: ";
	cin >> value;
	if (series.valueExists(value)) text = "\nThe data value is contained\n";
	else text = "\nThis value is not contained\n";
	cout << text;
}