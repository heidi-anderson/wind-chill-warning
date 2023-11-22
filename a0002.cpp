#include "a0002.h"

double cold(int temp, int windSpeed)
{
    double windChill;
    windChill = 35.74 + 0.6215 * temp - 35.75 * pow(windSpeed, 0.16) + 0.4275 * temp * pow(windSpeed, 0.16);
    
    round(windChill);
    
    return windChill;
}

string windChillWarning(int temp, int windSpeed)
{
    double windChill = cold(temp, windSpeed);
    
    
    if(windChill >= 32)
    {
        return "None";
    }
    else if(windChill >= 0)
    {
        return "Minimal";
    }
    else if(windChill >= (-20))
    {
        return "Caution";
    }
    else if(windChill >= (-40))
    {
        return "Intermediate";
    }
    else
    {
        return "Extreme";
    }
    
}