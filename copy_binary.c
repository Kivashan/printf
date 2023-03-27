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
	int j = va_arg(ap, int);
	int len = 0;
	int len2, i = j;
	/* if i < 0 get absolute value of i */
	if (j < 0)
		return (-1);

	/* calculate length for str */
	for ( ; i != 0; i /= 2)
		len++;

	len2 = len;
	/* Initialise str */
	for (i = len - 1; i >= 0; i--)
	{
		int rem = j % 2;

		j = j / 2;
		buffer[*bp + i] = rem + 48;
	}
		*bp = *bp + len2;
	return (len2);
}
