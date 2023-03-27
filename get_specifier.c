#include "main.h"

/**
 * get_specifier - Checks format string after encountering a % for a conversion
 *  specifier, if a conversion specifier is found, copies arguments to buffer
 * @format: format string
 * @i: position of % in format string
 * @buffer: string to copy to
 * @buff_pos: positino of first empty element in buffer
 *
 * Return: the number of characters copied to buffer
 */

int get_specifier(const char *format, int *i, char *buffer, int *buff_pos)
{
	int j, flag = 0, count = 0;
	get print[] = {{"c", copy_char}, {"s", copy_string}, {NULL, NULL}};

	if (print_percent(format, i, buffer, buff_pos))
	{
		count++;
		continue;
	}

	j = 0;
	while (print[j].spec != NULL)
	{
		if (print[j].spec[0] == format[*i + 1])
		{
			count += (*print[j].case_func)(ap, buffer, buff_pos);
			*i = *i + 1;
			flag = 1;
			break;
		}
			j++;
	}
	if (flag == 0)
	{
		check_buffer(buffer, buff_pos);
		buffer[*buff_pos] = format[*i];
		*buff_pos = *buff_pos + 1;
		count++;
	}
	return (count);
}
