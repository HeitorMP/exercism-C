#include "phone_number.h"

void    clean_invalid_number(char *input)
{
    int i = 0;
    while (i < 10)
    {
        input[i] = '0';
        i++;
    }
    input[i] = '\0';
}

char *phone_number_clean(const char *input)
{
    char *result = (char *)calloc(13, sizeof(char));
    int i = 0;
    int j = 0;
    while (!isdigit(input[i]) || input[i] == '1')
        i++;
    while (input[i] != '\0')
    {
        if (isdigit(input[i]))
        {
            result[j] = input[i];
            j++;
        }      
        i++;
    }
    result[j] = '\0';

    if (strlen(result) != 10 || result[0] < '2' || result[3] < '2')
        clean_invalid_number(result);
    return result;
}