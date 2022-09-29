#include "minesweeper.h"


bool is_valid(char c)
{
    return (c == '*') ? false : true;
}

char **annotate(const char **minefield, const size_t rows)
{

    if (rows == 0)
        return NULL;
    size_t cols = strlen(minefield[0]);
    
    // init array;
    char **my_minefield = malloc(sizeof(char *) * rows);
    for (size_t i = 0; i < rows; i++)
    {
        my_minefield[i] = malloc(sizeof(char) * cols);
    }

    //copy array to my_array (mutable);
    for (size_t y = 0; y < rows; y++)
    {
        for (size_t x = 0; x < cols; x++)
        {
            if (minefield[y][x] == '*')
                my_minefield[y][x] = '*';
            else
                my_minefield[y][x] = '0';
        }
        my_minefield[y][cols] = '\0';
    }



    for (size_t y = 0; y < rows; y++)
    {
        for (size_t x = 0; x < cols; x++)
        {
            if (minefield[y][x] == '*')
            {   
                if (y > 0 && x > 0) 
                    if (is_valid(my_minefield[y - 1][x - 1])) my_minefield[y - 1][x - 1] += 1;
                
                if (y > 0 && x < cols - 1) 
                    if (is_valid(my_minefield[y - 1][x + 1])) my_minefield[y - 1][x + 1] += 1;
                    
                if (y < rows - 1 && x > 0) 
                    if (is_valid(my_minefield[y + 1][x - 1])) my_minefield[y + 1][x - 1] += 1;
                
                if (y < rows - 1 && x < cols - 1) 
                    if (is_valid(my_minefield[y + 1][x + 1])) my_minefield[y + 1][x + 1] += 1;
                    
                if (y > 0) 
                    if (is_valid(my_minefield[y - 1][x])) my_minefield[y - 1][x] += 1;
                
                if (y < rows - 1) 
                    if (is_valid(my_minefield[y + 1][x])) my_minefield[y + 1][x] += 1;
                    
                if (x > 0) 
                    if (is_valid(my_minefield[y][x - 1])) my_minefield[y][x - 1] += 1;
                
                if (x < cols - 1)
                    if (is_valid(my_minefield[y][x + 1])) my_minefield[y][x + 1] += 1;
            }
        } 
    }

    for (size_t y = 0; y < rows; y++)
    {
        for (size_t x = 0; x < cols; x++)
        {
            if (my_minefield[y][x] == '0')
            {   
               my_minefield[y][x] = ' ';
            }
        } 
    }

    return(my_minefield);
}

void free_annotation(char **annotation)
{
    free(annotation);
}

/*
int main (void)
{
    const char *minefield[] = {
      // clang-format off
      "  * ",
      " *  ",
      " *  ",
      "    "
      // clang-format on
   };
   char **teste = annotate(minefield, 4);
   
   for (int i = 0; i < 4; i++)
   {
        printf("%s\n", teste[i]);
   }
   free_annotation(teste);
}*/
