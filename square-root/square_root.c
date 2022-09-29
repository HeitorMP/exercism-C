#include "square_root.h"

UINT16   square_root(UINT16 number)
{
    if (number == 1)
        return 1;
    for (UINT16 i = 2; i <= number / 2; i++)
    {
        if (i * i == number)
            return i;
    }
    return 0;
}
