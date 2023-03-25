#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - printf formatted output
 * @format: format string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	va_list ap2;
	int i, count = 0;
	int len;
	char *s;
	char *tmp;

	va_start(ap, format);
	va_start(ap2, format);

	i = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		len = 0;
		while (format[i]  == '%')
		{
				switch (format[i + 1])
				{
					case 'c':
						count += _putchar(va_arg(ap, int));
						i = i + 2;
						break;
					case 'C':
                                                count += _putchar(va_arg(ap, int));
                                                i = i + 2;
                                                break;
					case 's':
						tmp = va_arg(ap, char *);
						if (!tmp)
						{
							count += _puts("(null)");
							i = i + 2;
							break;
						}
						len = _strlen(tmp);
						
						s = malloc(sizeof(char) * (len + 1));
						if (!s)
						{
							count += _puts("(null)");
							i = i + 2;
							break;
						}
						s = _strcpy(s, va_arg(ap2, char *));
						count += _puts(s);
						free(s);
						i = i + 2;
						break;
					case '%':
						count += _putchar('%');
						i = i + 2;
						break;
					default:
							count += _putchar('%');
							i = i + 1;
						break;
				}
			continue;
		}
		count += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	va_end(ap2);
	return (count);
}
