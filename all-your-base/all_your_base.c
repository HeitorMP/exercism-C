#include "all_your_base.h"

size_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, size_t input_length)
{
    size_t output = 0;
    size_t div = 0;

    (void)input_base;
    for (int16_t power = input_length; power >= 0; power--)
    {
        div = div + pow(digits[power - input_length], power);
    }
    while (div / output_base > 0)
    {
        output = (div % output_base) * 10;
        div = div / output_base;
    }
    return output;
}