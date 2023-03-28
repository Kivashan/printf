#include "main.h"

/**
 * get_specifier - Checks format string after encountering a % for a conversion
 *  specifier, if a conversion specifier is found, copies arguments to buffer
 * @ap: va_list
 * @fmt: format string
 * @i: position of % in format string
 * @buffer: string to copy to
 * @bp: positino of first empty element in buffer
 *
 * Return: the number of characters copied to buffer
 */
int get_specifier(va_list ap, const char *fmt,
	int *i, char *buffer, unsigned long int *bp)
{
	int count = 0, flag = 0;

	if (print_percent(fmt, i, buffer, bp))
	{
		count++;
		flag = 1; /* look at later */
	}
	if (flag == 0)
		flag = get_custom(ap, buffer, bp, i, fmt, &count);
	if (flag == 0)
		flag = get_non_custom(ap, buffer, bp, i, fmt, &count);
	if (flag == 0)
	{
		check_buffer(buffer, bp);
		buffer[*bp] = fmt[*i];
		*bp = *bp + 1;
		count++;
	}
	return (count);
}
