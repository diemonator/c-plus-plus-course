#include "gtest/gtest.h"
#include "ScanList.h"

#include <stdio.h>
using namespace std;

TEST(AddingItemToList,normalAdditionAssendingOrder)
{
    ScanList *list = new ScanList();
    list->AddScan(12);
    list->AddScan(4);
    EXPECT_EQ(list->getScanByNr(1)->getSerialNumber(),12);
    EXPECT_EQ(list->getScanByNr(0)->getSerialNumber(),4);
    delete list;
}

TEST(RecyclingItems,AddingTheSameItemAndCheckingWithGetScanNumber)
{
    ScanList *list = new ScanList();
    list->AddScan(4);
    list->AddScan(12);
    list->AddScan(4);
    list->AddScan(12);
    list->AddScan(4);
    EXPECT_EQ(list->getScanByNr(0)->getTimesRecycled(),3);
    EXPECT_EQ(list->getScanByNr(1)->getTimesRecycled(),2);
    delete list;
}

TEST(RecyclingItems,AddingTheSameItemUsingTimesRecycled)
{
    ScanList *list = new ScanList();
    list->AddScan(4);
    list->AddScan(12);
    list->AddScan(4);
    list->AddScan(12);
    list->AddScan(4);
    EXPECT_EQ(list->getTimesRecycled(12),2);
    EXPECT_EQ(list->getTimesRecycled(4),3);
    EXPECT_EQ(list->getTimesRecycled(6),0);
    delete list;
}

TEST(RemovingItems,RemovalOfFirstItem)
{
    ScanList *list = new ScanList();
    list->AddScan(12);
    list->AddScan(4);
    list->AddScan(4);
    list->AddScan(12);
    list->AddScan(4);
    EXPECT_EQ(true,list->removeScan(4));
    EXPECT_EQ(list->getScanByNr(0)->getSerialNumber(),12);
    delete list;
}

TEST(RemovingItems,RemovalOfLastItem)
{
    ScanList *list = new ScanList();
    list->AddScan(12);
    list->AddScan(4);
    list->AddScan(4);
    list->AddScan(12);
    list->AddScan(4);
    EXPECT_EQ(true,list->removeScan(12));
    EXPECT_EQ(list->getScanByNr(0)->getSerialNumber(),4);
    delete list;
}

TEST(RemovingItems,RemovalOfMiddleItem)
{
    ScanList *list = new ScanList();
    list->AddScan(12);
    list->AddScan(4);
    list->AddScan(4);
    list->AddScan(12);
    list->AddScan(4);
    list->AddScan(8);
    EXPECT_EQ(true,list->removeScan(8));
    EXPECT_EQ(list->getScanByNr(1)->getSerialNumber(),12);
    delete list;
}