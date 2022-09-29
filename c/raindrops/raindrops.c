#include "raindrops.h"
#include <string.h>

int count_digits(int nbr)
{
    int digits = 0;
    while (nbr != 0)
    {
        digits++;
        nbr /= 10;
    }
    return digits;
}

char *convert(char result[], int drops)
{
    int control = 0;
    
    if (drops % 3 == 0)
        strcat(result, "Pling");
    else
        control++;
    
    if (drops % 5 == 0)
        strcat(result, "Plang");
    else
        control++;
    
    if (drops % 7 == 0)
        strcat(result, "Plong");
    else
        control++;

    if (control == 3)
    {
        int len = count_digits(drops);
        char strdrops[len];
        for (int i = len -1; i >= 0; i--)
        {
            strdrops[i] = drops % 10 + '0';
            drops = drops / 10;
        }
        strdrops[len] = '\0';
        strcat(result, strdrops);
    }
    return result;
}
