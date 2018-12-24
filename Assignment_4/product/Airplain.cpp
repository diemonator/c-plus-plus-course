#include "Airplain.h"

Airplain::Airplain(int nrOfEngines) : nrOfEngines(1), isFlying(false)
{ 
    this->nrOfEngines = nrOfEngines;
}

Airplain::~Airplain()
{ }

void Airplain::flysOff()
{
    isFlying = true;
}

void Airplain::land()
{
    isFlying = false;    
}

int Airplain::getNrOfEngines() const
{
    return nrOfEngines;
}

void Airplain::currentState() {
    if (isFlying) cout << "Plane is flying" << endl;
    else cout << "Plane has landed" << endl;
}