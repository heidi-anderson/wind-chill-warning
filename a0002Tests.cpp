#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0002.h"
#include <cmath>

TEST_CASE("cold - testing extreme temp with low windspeed")
{
    double windChill;
    int temp = 45;
    int windSpeed = 3;
    
    windChill = cold(temp, windSpeed);
    REQUIRE(round(windChill) == round(44.02174));
}


TEST_CASE("cold - testing low temp with extreme windspeed")
{
    double windChill;
    int temp = (-10);
    int windSpeed = 99;
    
    windChill = cold(temp, windSpeed);
    REQUIRE(round(windChill) == round(-53.9647));
}


TEST_CASE("cold - testing extreme temp with high windspeed")
{
    double windChill;
    int temp = 50;
    int windSpeed = 76;
    
    windChill = cold(temp, windSpeed);
    REQUIRE(round(windChill) == round(38.07161));
}


TEST_CASE("cold - testing low temp with low windspeed")
{
    double windChill;
    int temp = (-12);
    int windSpeed = 3;
    
    windChill = cold(temp, windSpeed);
    REQUIRE(round(windChill) == round(-20.454));
}

TEST_CASE("windChillWarning - testing None, Ta = 38, v = 8")
{
    int temp = 38;
    int windSpeed = 8;
    string warning;
    
    warning = windChillWarning(temp, windSpeed);
    REQUIRE(warning == "None");
}

TEST_CASE("windChillWarning - testing None, Ta = 26, v = 3")
{
    int temp = 26;
    int windSpeed = 3;
    string warning;
    
    warning = windChillWarning(temp, windSpeed);
    REQUIRE(warning == "Minimal");
}

TEST_CASE("windChillWarning - testing Caution, Ta = 8, v = 8")
{
    int temp = 8;
    int windSpeed = 8;
    string warning;
    
    warning = windChillWarning(temp, windSpeed);
    REQUIRE(warning == "Caution");
}

TEST_CASE("windChillWarning - testing Intermediate, Ta = 0, v = 40")
{
    int temp = 0;
    int windSpeed = 40;
    string warning;
    
    warning = windChillWarning(temp, windSpeed);
    REQUIRE(warning == "Intermediate");
}

TEST_CASE("windChillWarning - testing Extreme, Ta = -16, v = 34")
{
    int temp = (-16);
    int windSpeed = 34;
    string warning;
    
    warning = windChillWarning(temp, windSpeed);
    REQUIRE(warning == "Extreme");
}