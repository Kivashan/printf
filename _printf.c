#include <stdio.h>
#include <stdarg.h>
#include "main.h"
int _printf(const char * format,...)
{
	char *buffer;
	int i, j, 
	unsigned long int buff_pos = 0;
	va_list ap;
	get print[] = {{"c", copy_char},{"s", copy_string},{"\0", "\0"}};

	va_start(ap, format);
	if (!format)
		return (-1);
	buffer = malloc(1024);
	if (!buffer)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (print_percent(format, &i, buffer, &buff_pos))/*append % to buffer and increment i by 2*/
				continue;/*is it necessary?*/
			j = 0;
			while (print[j].spec != "\0")
			{
				if (print[j].spec == format[i])
				{
					(*print[j].case_func)(ap, buffer, &buff_pos);
					i = i + 2;
				}
				j++;
			} continue;
		}
		buffer[buff_pos] = format[i];
		buff_pos++;
	}
	va_end(ap);
	return (buff_pos);
}
