#include <string>
#include <iostream>
#include "gtest/gtest.h"
#include "Truck.h"

using namespace std;

// Truck destructor
TEST(DestructorTruck, truck1)
{
    Truck *truck = new Truck("model","material",20,35,100);
    Truck *truck2 = new Truck("Benz","Steel",25,4,100);
    delete truck;
    delete truck2;
}

// Truck copy
TEST(CopyTruck, copyCheck) 
{
    Truck truck("model","material",15,6,150);
    Truck *newTruck = new Truck(truck);
    ASSERT_EQ(truck.getNrWheels(),newTruck->getNrWheels());
    truck.removeWheel(1);
    EXPECT_EQ(5,truck.getNrWheels());
    EXPECT_EQ(6,newTruck->getNrWheels());
    newTruck->removeWheel(5);
    EXPECT_EQ(newTruck->getNrWheels(),truck.getNrWheels());
    delete newTruck;
}

// Truck assignment operator
TEST(AssignmentTruck, WheelsCheck) 
{
    Truck truck("truck","material",15,6,150);
    Truck *truck1 = &truck;
    truck.removeWheel(1);
    EXPECT_EQ(truck1->getNrWheels(),5);
}

TEST(AssignmentTruck, PowerCheck) 
{
    Truck truck("truck","material",15,6,150);
    Truck *truck1 = &truck;
    EXPECT_EQ(truck1->getPower(),150);
}
