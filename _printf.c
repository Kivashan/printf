#include "main.h"

/**
 * _printf - prints a formatted string
 * @format: format string to print
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	char *buffer;
	int i, count = 0;
	unsigned long int buff_pos = 0;
	va_list ap;

	va_start(ap, format);
	if (!format)
		return (-1);
	buffer = malloc(1025);
	if (!buffer)
		return (0);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += get_specifier(ap, format, &i, buffer, &buff_pos);
			continue;
		}
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			print_buffer(buffer, &buff_pos);
			return (-1);
		}
		check_buffer(buffer, &buff_pos);
		buffer[buff_pos] = format[i];
		buff_pos++;
		count++;
	}
	print_buffer(buffer, &buff_pos);
	va_end(ap);
	return (count);
}
