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
	int len2;
	/* if i < 0 get absolute value of i */
	if (j < 0)
		j = _abs(j);

	/* calculate length for str */
	for ( ; j != 0; j /= 2)
		len++;

	len2 = len;
	/* Initialise str */
	for ( ; len >= 0; len--)
	{
		int rem = j % 2;

		j = j / 2;
		buffer[*bp + len] = rem + 48;
	}
	return (len2);
}
