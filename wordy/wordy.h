#ifndef WORDY_H
#define WORDY_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
bool answer(const char *question, int *result);
int	str_is_numeric(char *str);
int count_words(char *str);
bool is_valid_question(char *str);
bool is_valid_operator(char *str);

#endif
