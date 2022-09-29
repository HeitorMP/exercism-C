#include "acronym.h"

/* chars that separate the words */
int my_isspace(char c)
{
    return (isspace(c) ||  c == '-' || c == '_');
}

/* returns the size of the new string that will store the result */
int acron_size(const char *phrase)
{
    int size;
    for (int i = 0; phrase[i] != '\0'; i++)
    {
        if (my_isspace(phrase[i]))
            size++;
    }
    return (size + 1);
}

char *abbreviate(const char *phrase)
{
    if (!phrase || phrase[0] == '\0')
        return NULL;

    char *acronym = malloc(sizeof(char) * acron_size(phrase));

	int i = 0;
    while (my_isspace(phrase[i])) { i++; }

    acronym[0] = toupper(phrase[i]);
    for (int j = i; phrase[j] != '\0'; j++)
    {
        if (my_isspace(phrase[j]) && !my_isspace(phrase[j + 1]))
            acronym[strlen(acronym)] = toupper(phrase[j + 1]);
    }
    return acronym;
}
