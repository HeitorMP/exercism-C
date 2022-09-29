#include "grains.h"

uint64_t square(uint8_t index)
{
    if (index < 1 || index > 64)
        return 0;
    if (index == 1)
        return 1;
    uint64_t grains = 1;
    for (uint8_t square = 2; square <= index; square++)
    {
        grains = grains * 2;
    }
    return  (grains);
}

uint64_t total(void)
{
    return (UINT64_MAX);
}
