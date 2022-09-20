#include "darts.h"




uint8_t score(coordinate_t landing_position)
{
    float x = landing_position.x;
    float y = landing_position.y;

    /***********************************************************************************
     *  Distance formula find at:                                                      *
     *  https://technotip.com/7339/c-program-to-calculate-distance-between-two-points/ *
     *                                                                                 *
     *  distance = sqrt( (x2 – x1) * (x2 – x1) + (y2 – y1) * (y2 – y1) );              *
     *  but x1 = 0 and y1 = 0                                                            *
     *                                                                                 *
     **********************************************************************************/
    float distance = sqrt(x*x + y*y); 

    if (distance <= 1)
        return 10;
    else if (distance <= 5)
        return 5;
    else if (distance <= 10)
        return 1;
    return 0;
}