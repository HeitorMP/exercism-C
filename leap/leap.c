#include "leap.h"

bool leap_year(int year)
{
    if ((year % 4 == 0))
    {
        if (year % 100 == 0)
            return (year % 400 == 0) ? true : false;
        return true;
    }
    return false;
}
