#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>
#include <math.h>

typedef struct coordinate_s
{
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t landing_position);

#endif
