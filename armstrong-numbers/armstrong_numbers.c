#include "armstrong_numbers.h"
#include <math.h>
bool is_armstrong_number(int candidate)
{
    int    countDigits = 0;
    int    tempCandidate = candidate;

    if (candidate < 0 )
        return 0; // false
    while (tempCandidate != 0)
    {
        countDigits++;
        tempCandidate /= 10;
    }
    tempCandidate = candidate;
    int    sum = 0;
    while (tempCandidate != 0)
    {
        sum += pow((tempCandidate % 10), countDigits);
        tempCandidate /= 10;
    }
    if (sum == candidate)
        return 1; // true
    return 0; // false
}