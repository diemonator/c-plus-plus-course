#include "menu.h"

int main(void)
{
    ScanList list;
    createDummyData(&list);
    cout << "Recycling console application" << endl;
    showMenu();
    int choice = 0;
    while (choice != 5)
    {
        cin >> choice;
        switch(choice)
        {
            case 1:
            showScans(&list);
            break;
            case 2:
            addScan(&list);
            break;
            case 3:
            removeFromList(&list);
            break;
            case 4:
            return 1;
            break;
        }
        showMenu();
    }
    return 0;
}

void showMenu()
{
    cout << "Type 1 to display list" << endl;
    cout << "Type 2 to add to list" << endl;
    cout << "Type 3 to remove from list" << endl;
    cout << "Type 4 to exit" << endl << endl;
    cout << "Type number here: ";
}

void createDummyData(ScanList *list)
{
    list->AddScan(101);
    list->AddScan(89);
    list->AddScan(102);
    list->AddScan(101);
    list->AddScan(70);
    list->AddScan(1);
    list->AddScan(2);
    list->AddScan(3);
}

void showScans(ScanList *list)
{
    cout << "Can info:" << endl;
    for (int i = 0; list->getScanByNr(i) != nullptr; i++)
    {
        Scan *scan = list->getScanByNr(i);
        cout << i << ")Can serialNr: " << scan->getSerialNumber() << ", times recycled: " << scan->getTimesRecycled() << endl;
    }
    cout << endl;
}

void addScan(ScanList *list)
{
    int serial = 0;
    cout << "Enter serial: ";
    cin >> serial;
    list->AddScan(serial);;
}

void removeFromList(ScanList *list)
{
    int serial;
    cout << "Enter serial: ";
    cin >> serial;
    list->removeScan(serial);
}