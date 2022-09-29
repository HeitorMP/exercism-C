#ifndef ACRONYM_H
#define ACRONYM_H
 
 #include <ctype.h>
 #include <stdlib.h>
 #include <string.h>

int my_isspace(char c);
int acron_size(const char *phrase);
char *abbreviate(const char *phrase);

#endif
