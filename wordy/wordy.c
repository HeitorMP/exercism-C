#include "wordy.h"

int	str_is_numeric(char *str)
{
	int	i = 0;

    if (str[0] == '+' || str[0] == '-')
	    i = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int count_words(char *str)
{
    int i = 0;
    int size = 0;
    while(str[i]) 
    {
        if (str[i] == ' ')
            size++;
        i++;
    }
    return (size + 1);
}

bool is_valid_question(char *str)
{  
    return (strncmp(str, "What is ", 8) != 0) ? false : true;
}

bool is_valid_operator(char *str)
{
    if (strcmp(str, "plus") == 0)
        return true;
    else if (strcmp(str, "minus") == 0)
        return true;
    else if (strcmp(str, "by") == 0)
        return true;
    else if (strcmp(str, "multiplied") == 0)
        return true;
    else if (strcmp(str, "divided") == 0)
        return true;
    
    return false;
}

bool answer(const char *question, int *result)
{
    char *token;
    char **final_token;

    char temp_question[strlen(question)];  // to make a alterable string;
    strcpy(temp_question, question);


    if (!is_valid_question(temp_question))
        return false;


    if (temp_question[strlen(temp_question) - 1] == '?') // to remove the '?' from last position.
        temp_question[strlen(temp_question) - 1] = '\0';

    int size = count_words(temp_question); // size of array;
    
    final_token = malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++)
    {
        final_token[i] = (char *)malloc(sizeof(char) * 10);
    }

    token = strtok(temp_question, " "); // first token   
    int i = 0;
    while (token != NULL)              // loop through the string to extract all other tokens
    {
        final_token[i] = token;
        token = strtok(NULL, " ");
        i++;   
    }

    int ii = 0;
    int count_numbers = 0;
    while (ii < size)
    {
        if (str_is_numeric(final_token[ii]))
            count_numbers++;    
        ii++;
    }
    if (count_numbers < 2 && !str_is_numeric(final_token[size - 1]))
        return false;
    else
        *result = atoi(final_token[2]);


    int index = 3;
    int temp_number = 0;
    while (index < size)
    {  
        if (strcmp(final_token[index], final_token[index-1]) == 0)
            return false;
        if (str_is_numeric(final_token[index]))
        {
            if (str_is_numeric(final_token[index - 1]))
                return false;
            temp_number = atoi(final_token[index]);
            if (strcmp(final_token[index - 1], "plus") == 0)
            {
                *result += temp_number;
            }
            else if (strcmp(final_token[index - 1], "minus") == 0)
            {
                *result -= temp_number;
            }
            else if (strcmp(final_token[index - 1], "by") == 0)
            {
                if (strcmp(final_token[index - 2], "divided") == 0)
                    *result /= temp_number;
                else if (strcmp(final_token[index - 2], "multiplied") == 0)
                    *result *= temp_number;
            }          
        }
        index++;
    }
    return (true);
}