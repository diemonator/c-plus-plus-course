#include <string>
#include "gtest/gtest.h"
#include "MeasurementSeries.h"

using namespace std;

TEST(TestName, EmptyName)
{
    MeasurementSeries m;
    EXPECT_EQ(m.getName(),"NoName");
}

TEST(TestName, WithName)
{
    string name = "Emil";
    MeasurementSeries m(name);
    EXPECT_EQ(m.getName(),name);
}

TEST(TestName, WithFunctionName)
{
    string name = "Emil";
    MeasurementSeries m;
    m.setName(name);
    EXPECT_EQ(m.getName(),name);
}

TEST(TestTheSeries, CheckIfFull)
{
    MeasurementSeries m;
    EXPECT_FALSE(m.isFull());
}

TEST(TestTheSeries, AddingValue)
{
    MeasurementSeries m;
    m.addValue(35);
    m.addValue(16);
    EXPECT_EQ(m.getValue(0),35);
    EXPECT_EQ(m.getValue(1),16);
}

TEST(TestTheSeries, AddingValue)
{
    MeasurementSeries m;
    m.addValue(35);
    m.addValue(16);
    EXPECT_EQ(m.getValue(0),35);
    EXPECT_EQ(m.getValue(1),16);
}