#include "series.h"

slices_t slices(char *input_text, unsigned int substring_length)
{
    slices_t    result;
    result.substring = calloc(sizeof(char**), MAX_SERIES_RESULTS);
    result.substring_count = 0;

    if (substring_length == 0)
    {
        result.substring[0] = NULL;
        return (result);
    }    

    if ((substring_length == strlen(input_text)))
    {
        result.substring[0] = (char *)calloc(sizeof(char), strlen(input_text));
        strcpy(result.substring[0], input_text);
        result.substring_count++;
        return (result);
    }    

    for (unsigned int i = 0; i < strlen(input_text) - substring_length + 1; i++)
    {
        result.substring[i] = calloc(sizeof(char*), substring_length);
        strncpy(result.substring[i], input_text + i, substring_length);
        result.substring_count++;
    }
    return (result);
}