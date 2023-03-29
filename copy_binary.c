#include "main.h"

/**
 * copy_binary - converts i to binary
 * @ap: va_list, calling va_arg for integer argument
 * @buffer: buffer to store binary
 * @bp: position of next empty element in buffer
 *
 * Return: Pointer to a string
 */

int  copy_binary(va_list ap, char *buffer, unsigned long int *bp)
{
	/*char *str;*/
	unsigned int k, j = va_arg(ap, int);
	int i;
	int len2, len = 0;
	char *str;

	k = j;
	if (j == 0)
	{
		buffer_update('0', buffer, bp);
		return (1);
	}
	/* calculate length for str */
	for ( ; k != 0; k /= 2)
		len++;

	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (-1);
	len2 = len;
	/* Initialise str */
	for (i = len - 1; i >= 0; i--)
	{
		int rem = j % 2;

		j = j / 2;
		str[i] = rem + 48;
	}
	for (i = 0; i < len; i++)
		buffer_update(str[i], buffer, bp);
	free(str);
	return (len2);
}
