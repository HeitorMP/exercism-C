#include "pascals_triangle.h"

uint8_t **create_triangle(size_t rows)
{
        if (rows == 0) 
        {
		    uint8_t **triangle;
		    triangle = calloc(1, sizeof(uint8_t *));
		    *triangle = calloc(1, sizeof(uint8_t));
		    triangle[0][0] = 0;
		return triangle;
	    }
        uint8_t **triangle = calloc(rows, sizeof(uint8_t *));
        for (uint8_t i = 0; i < rows; i++)
        {
            triangle[i] = calloc(rows, sizeof(uint8_t));
        }
        triangle[0][0] = 1;
        for (uint8_t i = 1; i < rows; i++)
        {
            for (uint8_t j = 0; j < rows; j++)
            {
                triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
            }
        }
    return triangle;
}

void free_triangle(uint8_t **triangle, size_t rows)
{
    for (uint8_t i = 0; i < rows; i++)
    {
        free(triangle[i]);
    }
    free(triangle);
}