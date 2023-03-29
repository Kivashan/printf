#include "main.h"

/**
 * copy_ax - converts i to binary
 * @ap: va_list, calling va_arg for integer argument
 * @buffer: buffer to store binary
 * @bp: position of next empty element in buffer
 *
 * Description: convert number to binary
 * Return: Pointer to a string
 */

int  copy_ax(va_list ap, char *buffer, unsigned long int *bp)
{
	unsigned long int k, j = (va_arg(ap, unsigned long int));
	int i, len = 0;
	char *str, *hex = "0123456789abcdef";

	k = j;
	if (j == 0)
	{
		char *nil = "(nil)";
		*bp = *bp - 2;
		for (i = 0; nil[i]; i++)
			buffer_update(nil[i], buffer, bp);
		return (-1);
	}
	if (j < 16)
	{
		buffer_update(hex[j], buffer, bp);
		return (1);
	}
	for ( ; k != 0; k /= 16)
		len++;

	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	/* Initialise str */
	for (i = len - 1; i >= 0; i--)
	{
		int rem = j % 16;

		j = j / 16;
		str[i] = hex[rem];
	}
	for (i = 0; i < len; i++)
		buffer_update(str[i], buffer, bp);
	free(str);
	return (len);
}
