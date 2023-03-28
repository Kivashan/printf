#include "main.h"

/**
 * get_non_custom - checks for conversion specifier and copies to buffer if
 * specifier is found
 * @ap: va_arg argument
 * @buffer: string to copy into
 * @bp: position of first empty element in buffer
 * @i: position of current element we are checking in fmt string
 * @fmt: format string
 * @count: number of characters copied into buffer
 *
 * Return: 1 if specifier was found and 0 otherwise
 */
int get_non_custom(va_list ap, char *buffer, unsigned long int *bp, int *i,
	const char *fmt, int *count)
{
	int flag = 0;
	int j = 0;

	get print[] = {
		{"c", copy_char},
		{"s", copy_string},
		{"d", copy_int},
		{"i", copy_int},
		{"u", copy_u},
		{"x", copy_hex},
		{"X", copy_HEX},
		{"o", copy_octal},
		{"p", copy_address},
		{NULL, NULL}};

	while (print[j].spec != NULL)
	{
		if (print[j].spec[0] == fmt[*i + 1])
		{
			*count += (*print[j].case_func)(ap, buffer, bp);
			*i = *i + 1;
			flag = 1;
			break;
		}
		j++;
	}
	return (flag);
}
