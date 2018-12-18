#include "Airplain.h"

Airplain::Airplain(int nrOfEngines) : isFlying(false), nrOfEngines(1)
{ }

Airplain::~Airplain()
{ }

void Airplain::FlysOff()
{
    isFlying = true;
}

void Airplain::Land()
{
    isFlying = false;    
}

int Airplain::getNrOfEngines() const
{
    return nrOfEngines;
}