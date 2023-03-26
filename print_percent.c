#include "main.h"

/**
 * print_percent - checks if %% exist at i in format string
 * copies % to buffer if true
 * @format: format string
 * @i: pointer to intger I
 * @buffer: string to copy to
 *
 * Return: 1 if %%, 0 otherwise
 */

int print_percent(const char *format, int *i, char *buffer, unsigned long int *buff_pos)
{

	if (format[*i + 1] == '%')
	{
		buffer[*buff_pos] = format[*i + 1];
		*buff_pos = *buff_pos + 1;
		check_buffer(buffer, buff_pos);
		*i = *i + 1;
		return (1);
	}
	return (0);
}
