#include "ScanList.h"

ScanList::ScanList() : scans(nullptr)
{ }

ScanList::~ScanList()
{
    Scan *scan = scans;
    while (scan != nullptr)
    {
        Scan *curScan = scan;
        scan = scan->getNext();
        delete curScan;
    }
}
// OK
void ScanList::AddScan(int serialNumber)
{
    if (scans == nullptr)
    {
        scans = new Scan(serialNumber);
        return;
    }
    Scan *scan = scans;
    while (scan != nullptr && scan->getSerialNumber() != serialNumber)
    {
        scan = scan->getNext();
    }
    if (scan == nullptr) 
    {
        Scan *curScan = scans;
        if (curScan->getSerialNumber() > serialNumber)
        {
            Scan *next = curScan;
            scans = new Scan(serialNumber);
            scans->setNext(next);
            return;
        }
        while (curScan->getSerialNumber() < serialNumber)
        {
            Scan *next = curScan->getNext();  
            if (next == nullptr || next->getSerialNumber() > serialNumber) 
            {
                Scan* newScan = new Scan(serialNumber);
                newScan->setNext(next);
                curScan->setNext(newScan);
                break;
            }
            curScan = curScan->getNext();
        }
    }
    else scan->recycle();
}

// OK
Scan* ScanList::getScanByNr(int position)
{
    int counter = 0;
    Scan *scan = scans;
    while (scan != nullptr)
    {
        counter++;
        scan = scan->getNext();
    }
    if (position >= 0 && position < counter)
    {
        counter = 0;
        scan = scans;
        while(scan != nullptr)
        {
            if (position == counter)
                return scan;
            counter++;
            scan = scan->getNext();
        } 
    }
    return nullptr;
    
}
// pre: -
// post: IF 0 <= position < nr of scans in the list
// THEN return a pointer to the scan at that position
// ELSE return NULL
bool ScanList::removeScan(int serialNumber)
{
    if (scans != nullptr)
    {
        Scan *previous = nullptr;
        Scan *current = scans;
        while (current != nullptr)
        {
            if (current->getSerialNumber() == serialNumber) 
            {
                if (previous == nullptr)
                {
                    current = scans->getNext();
                    delete scans;
                    scans = current;
                }
                else 
                {
                    previous->setNext(current->getNext());
                    delete current;
                }
                return true;
            }
            previous = current;
            current = current->getNext();
        }
    }
    return false;
}
// OK
int ScanList::getTimesRecycled(int serialNumber)
{
    Scan *scan = scans;
    while (scan != nullptr)
    {
        if (scan->getSerialNumber() == serialNumber)
        {
            return scan->getTimesRecycled();
        }
        scan = scan->getNext();
    }
    return 0;
}