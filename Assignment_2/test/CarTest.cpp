#include <string>
#include "gtest/gtest.h"
#include "Car.h"

using namespace std;

// Car destructor
TEST(CarDestructor, deletion)
{
    Car *car = new Car("model","material",20,35);
    Car *car2 = new Car("Benz","Steel",25,4);
    delete car;
    delete car2;
}

// Car copy
TEST(CarDeepCopy, NrOfWheelsCheck)
{
    Car car("model","material",15,6);
    Car *newCar = new Car(car);
    ASSERT_EQ(car.getNrWheels(),newCar->getNrWheels());
    car.removeWheel(1);
    EXPECT_EQ(5,car.getNrWheels());
    EXPECT_EQ(6,newCar->getNrWheels());
    newCar->removeWheel(5);
    EXPECT_EQ(newCar->getNrWheels(),car.getNrWheels());
    delete newCar;
}

// Car assignment operator
TEST(CarAssignmentTest, NrOfWheels)
{
    Car car("model","material",15,6);
    Car *car1 = &car;
    car.removeWheel(1);
    EXPECT_EQ(car.getNrWheels(),5);
    EXPECT_EQ(car1->getNrWheels(),5);
}

TEST(CarAssignmentTest, CarModel)
{
    Car car("model","material",15,6);
    Car *car1 = &car;
    EXPECT_EQ(car1->getModel(),"model");
}