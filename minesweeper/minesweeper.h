#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **annotate(const char **minefield, const size_t rows);
void free_annotation(char **annotation);
bool is_valid(char c);

#endif
