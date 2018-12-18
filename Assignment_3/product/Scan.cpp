#include "Scan.h"

Scan::Scan(int number) : serialNumber(number), timesRecycled(1), next(nullptr)
{

}

Scan::~Scan() 
{ }

int Scan::getSerialNumber() 
{
    // return serialNumber;
    return this->serialNumber;
}

Scan* Scan::getNext()
{
    // return (Scan*)next;
    return this->next;
}

void Scan::setNext(Scan* nextScan)
{
    this->next = nextScan;
}

void Scan::recycle()
{
    this->timesRecycled++;
}

int Scan::getTimesRecycled()
{
    return this->timesRecycled;
}