#include "main.h"
#include <stdarg.h>

/**
 * _printf - printf formatted output
 * @format: format string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int flag, i, j, count = 0;
	char ch, *s;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		while (format[i]  == '%')
		{
			j = 1;
			flag = 0;
			while (flag == 0)
			{
				switch (format[i + j])
				{
					case 'c':
						ch = va_arg(ap, int);
						if (!ch)
							return (-1);
						count += _putchar(ch);
						flag = 1;
						break;
					case 's':
						s = va_arg(ap, char *);
						if (!s)
							return (-1);
						count += _puts(s);
						flag = 1;
						break;
					case '%':
						if (j == 1)
						{
							_putchar('%');
						}
						flag = 1;
						break;
					default:
						break;
				}
			j++;
			}
			i = i + j;
			continue;
		}
		count += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
