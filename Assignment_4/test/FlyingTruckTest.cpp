#include <string>
#include "gtest/gtest.h"
#include "Airplain.h"
#include "FlyingTruck.h"
#include "Truck.h"

using namespace std;

TEST(Hello, TestOne)
{
    FlyingTruck *flyingTruck = new FlyingTruck("daf","aluminium",15,2);
    flyingTruck->drive();
    flyingTruck->Truck::currentState();
    flyingTruck->stop();
    flyingTruck->Truck::currentState();
    delete flyingTruck;
}

TEST(Hello1, TestOne)
{
    FlyingTruck *flyingTruck = new FlyingTruck("daf","aluminium",15,2);
    flyingTruck->flysOff();
    flyingTruck->Airplain::currentState();
    flyingTruck->land();
    flyingTruck->Airplain::currentState();
    delete flyingTruck;
}

TEST(TestValues, TestOneDefaultValues)
{
    FlyingTruck *flyingTruck = new FlyingTruck("daf","aluminium",15,2);
    EXPECT_EQ(flyingTruck->getFlyingBoolean(),false);
    EXPECT_EQ(flyingTruck->getDrivingBoolean(),false);
    delete flyingTruck;
}

TEST(TestValues, TestTwoNonDefaultValues)
{
    FlyingTruck *flyingTruck = new FlyingTruck("daf","aluminium",15,2);
    flyingTruck->flysOff();
    EXPECT_EQ(flyingTruck->getFlyingBoolean(),true);
    EXPECT_EQ(flyingTruck->getDrivingBoolean(),false);
    delete flyingTruck;
}

TEST(TestValues, TestTwoNonDefaultValues2)
{
    FlyingTruck *flyingTruck = new FlyingTruck("daf","aluminium",15,2);
    EXPECT_EQ(flyingTruck->getPower(),15);
    EXPECT_EQ(flyingTruck->getNrOfEngines(),2);
    delete flyingTruck;
}