#include "FlyingTruck.h"

FlyingTruck::FlyingTruck(const string& model, const string& material, int power, int nrOfEngines) : Truck(model,material,power), Airplain(nrOfEngines)
{ }

FlyingTruck::~FlyingTruck()
{ }

void FlyingTruck::currentState()
{
    if (isFlying && isDriving)
        cout << "Is flying and driving at the same time! LOL" << endl;
    else if (!isFlying && !isDriving)
        cout << "Stupid truck/ airplaine. I don't know even know what you are?" << endl;
    else if (isFlying && !isDriving)
        cout << "Hey look a fling truck!" << endl;
    else if (!isFlying && isDriving)
        cout << "Hey look a driving plain!" << endl;
}

bool FlyingTruck::getFlyingBoolean()
{
    return isFlying;
}

bool FlyingTruck::getDrivingBoolean()
{
    return isDriving;
}