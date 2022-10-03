#include "luhn.h"

bool luhn(const char *num)
{
    size_t sum = 0;
    size_t count_space = 0;  
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (!isdigit(num[i]) && num[i] != ' ')
            return false;
        if (isspace(num[i]))
            count_space++;
    }

    int size = strlen(num) - count_space;
    if (size < 2)
            return false;

    
    char *my_num = malloc(sizeof(char) * size + 1);
    size_t i = 0;
    size_t j = 0;
    while (i < strlen(num))
    {
        if (num[i] != ' ')
        {
            my_num[j] = num[i];
            j++;
        }
        i++;
    }
    my_num[size] = '\0';
    int element = 1;
    for (int i = strlen(my_num) - 1; i > -1; i--)
    {
        int aux;
        aux = my_num[i] - '0';
        if (element % 2 == 0)
        {
            aux =  aux * 2;
            if (aux > 9)
                aux = aux - 9;
        }
        element++;
        sum += aux;
    }
    free(my_num);
    return (sum % 10 == 0) ? true : false;
}
