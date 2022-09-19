#include "resistor_color.h"

 static const resistor_band_t mycolors[] =
    {
        BLACK, BROWN, RED, ORANGE, YELLOW,
        GREEN, BLUE, VIOLET, GREY, WHITE
    };
int    color_code(resistor_band_t colors)
{
    return (colors);
}

const resistor_band_t *colors(void)
{
    return mycolors;
}