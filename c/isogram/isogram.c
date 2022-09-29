#include "isogram.h"
#include <stdio.h>
#include <ctype.h>

bool    is_isogram(const char phrase[])
{
    if (phrase == NULL)
        return false;
    bool    alpha[26] = {false};
    for (int i = 0; phrase[i] != '\0'; i++)
    {    
        if (isalpha((unsigned char)phrase[i]))
        {
            int alpha_i = tolower((unsigned char)phrase[i]) - 'a';
            if (alpha[alpha_i])
                return false;
            alpha[alpha_i] = true; 
        }
    }
    return true;
}