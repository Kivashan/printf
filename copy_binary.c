#include "main.h"

/**
 * print_binary - converts i to binary
 * @i: Integer to convert to binary
 *
 * Return: Pointer to a string
 */

char *i_to_binary(int i)
{
	char *str;
	int j = i;
	int len = 0;
	
	/* if i < 0 get absolute value of i */
	if (i < 0)
		i = _abs(i);

	/* calculate length for str */
	for (j = i; j != 0; j /= 2)
		len++;

	/* allocate memory to str to hold binary of i */
	str = malloc(sizeof(char) * (len + 1));

	/* check if malloc failed */
	if (!str)
		return (NULL);

	/* Initialise str */
	for (j = len - 1; j >= 0; j--)
	{
		int rem = i % 2;
		i = i / 2;
		str[j] = rem + 48;
	}

	return (str);
}
