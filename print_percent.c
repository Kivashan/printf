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

int print_percent(char *format, int *i, char *buffer, int *buff_pos)
{
	if (format[i + 1] == '%')
	{
		buffer[buff_pos++] == '%';
		i = i + 2;
		return (1);
	}
	return (0);
}
