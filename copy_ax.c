#include "main.h"

/**
 * copy_hex - converts i to binary
 * @ap: va_list, calling va_arg for integer argument
 * @buffer: buffer to store binary
 * @bp: position of next empty element in buffer
 *
 * Return: Pointer to a string
 */

int  copy_ax(va_list ap, char *buffer, unsigned long int *bp)
{
	int *k;
	void *j = va_arg(ap,void *);
	int i, f;
	int len2, len = 0;
	char *str;
	char hex[16] = "0123456789abcdef";
	
	k = (int *)j;
	f = *k;
	if (f < 16)
	{
		buffer[*bp] = hex[f];
		*bp = *bp + 1;
		check_buffer(buffer, bp);
		return (1);
	}
	/* calculate length for str */
	for ( ; *k != 0; *k /= 16)
		len++;

	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (-1);
	len2 = len;
	/* Initialise str */
	for (i = len - 1; i >= 0; i--)
	{
		int rem = f % 16;

		f = f / 16;
		str[i] = hex[rem];
	}
	for (i = 0; i < len; i++)
	{
		buffer[*bp] = str[i];
		*bp = *bp + 1;
		check_buffer(buffer, bp);
	}
	free(str);
	return (len2);
}
