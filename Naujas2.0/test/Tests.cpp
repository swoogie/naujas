#include <gtest/gtest.h>
#include "../code/struct.hpp"
#include "../code/lib.hpp"

TEST(classTest, zmogustest)
{
    studentoSt studentas("Kebabas", "Ibrahimovicius");
    EXPECT_EQ("Kebabas", studentas.getVardas());
    EXPECT_EQ("Ibrahimovicius", studentas.getPavarde());
}

TEST(test, galutinisvid)
{
    studentoSt studentas("Kebabas", "Ibrahimovicius");
    vector<double> pazymiai = {5,2,6,1};
    studentas.galutinisrez(pazymiai, 9);

    EXPECT_EQ(6.8, studentas.getavgRez());   
}

TEST(test, galutinismed)
{
    studentoSt studentas("Kebabas", "Ibrahimovicius");
    vector<double> pazymiai = {3,2,5,6,4};
    studentas.galutinisrez(pazymiai, 10.0);

    EXPECT_EQ(7.6, studentas.getmedRez());   
}