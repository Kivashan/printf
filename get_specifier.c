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
	int j, flag = 0, count = 0;
	get print[] = {
		{"c", copy_char},
		{"s", copy_string},
		{"d", copy_int},
		{"i", copy_int},
		{"b", copy_binary},
		{"u", copy_int},
		{"o", copy_octal},
		{NULL, NULL}};

	if (print_percent(fmt, i, buffer, bp))
	{
		count++;
		flag = 1; /* look at later */
	}

	j = 0;
	while (print[j].spec != NULL)
	{
		if (print[j].spec[0] == fmt[*i + 1])
		{
			count += (*print[j].case_func)(ap, buffer, bp);
			*i = *i + 1;
			flag = 1;
			break;
		}
			j++;
	}
	if (flag == 0)
	{
		check_buffer(buffer, bp);
		buffer[*bp] = fmt[*i];
		*bp = *bp + 1;
		count++;
	}
	return (count);
}
