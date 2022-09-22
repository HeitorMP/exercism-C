#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void    clean_invalid_number(char *input);
char *phone_number_clean(const char *input);

#endif
