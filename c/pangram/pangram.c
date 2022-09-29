#include "pangram.h"

bool is_pangram(const char *sentence)
{
    char control[] = "abcdefghijklmnopqrstuvwxyz";
    int count = 0;
    
    if (sentence == NULL)
        return false;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        for (int j = 0; control[j] != '\0'; j++)
        {
            if (tolower(sentence[i]) == control[j])
            {
                control[j] = '\a';
                count++;
            }
        }
    }
    return (count == 26) ? true : false;
}
