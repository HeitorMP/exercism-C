#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length)
{
    if (!arr || length <= 0)
        return NULL;
    int start = 0;
    int end = length;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == value)
            return (int *)&arr[mid];
        else if (arr[mid] < value)
            start = mid + 1;
        else
            end = mid;
    }
    return NULL;
}