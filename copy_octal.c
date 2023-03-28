#include "main.h"
/**
 * copy_octal - copy octal num to buffer
 * @ap: va_list pointer
 * @buffer: pointer to print staging mem location
 * @bp: pointer to buffer position
 *
 * Description: covert number to octal and copy to buffer
 * Return: int len2
 */
int copy_octal(va_list ap, char *buffer, unsigned long int *bp)
{
	char *str;
	int len, i, len2;
	unsigned int rem, num, n;

	len = 0;
	n = va_arg(ap, int);

	if (n < 8)
	{
		buffer[*bp] = n + 48;
		*bp = *bp + 1;
		check_buffer(buffer, bp);
		return (1);
	}
	num = n;
	for (; n != 0; n = n / 8)
		len++;

	len2 = len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);

	for (i = len - 1; i >= 0; i--)
	{
		rem = num % 8;
		str[i] = rem + 48;
		num = num / 8;
	}
	for (i = 0; i < len2; i++)
	{
		buffer[*bp] = str[i];
		*bp = *bp + 1;
		check_buffer(buffer, bp);
	}
	free(str);
	return (len2);
}
