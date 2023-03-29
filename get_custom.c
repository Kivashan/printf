#include "main.h"

/**
 * get_custom - checks for conversion specifier and copies to buffer if
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
int get_custom(va_list ap, char *buffer, unsigned long int *bp, int *i,
	     const char *fmt, int *count)
{
	int flag = 0;
	int j = 0;

	get c_print[] = {
		{"b", copy_binary},
		{"R", rot_13},
		{"S", copy_S},
		{"r", copy_rev},
		{NULL, NULL}};

	while (c_print[j].spec != NULL)
	{
		if (c_print[j].spec[0] == fmt[*i + 1])
		{
			*count += (*c_print[j].case_func)(ap, buffer, bp);
			*i += 1;
			flag = 1;
			break;
		}
		j++;
	}
	return (flag);
}
