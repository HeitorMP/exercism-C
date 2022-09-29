#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
    unsigned int result = 0;

    if (number_of_factors == 1 && factors[0] == 0)
        return result;
    for (unsigned int i = 0; i < limit; i++)
    {
        for (unsigned int j = 0; j < number_of_factors; j++)
        {
            if (factors[j] == 0)
                break;
            if (i % factors[j] == 0)
            {
                result += i;
                break;
            }
        }
    }
    return result;
}
