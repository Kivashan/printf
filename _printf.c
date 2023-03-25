#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

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
		/*	j = 1;
			flag = 0;
			while (flag == 0)
			{*/
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
						len = _strlen(va_arg(ap, char *));
						s = malloc(sizeof(char) * (len + 1));
						if (!s)
							_puts("(null)"); 
						_strcpy(s, va_arg(ap2, char *));
						count += _puts(s);
						free(s);
						i = i + 2;
						break;
					/*case 'S':
                                                s = va_arg(ap, char *);
                                                if (!s)
                                                        s = "(null)";
                                                count += _puts(s);
                                                i = i + 2;
                                                break;*/
					case '%':
					/*	if (j == 1)
						{*/
							count += _putchar('%');
					/*	}*/
						i = i + 2;
						break;
					default:
							count += _putchar('%');
							i = i + 1;
						break;
				}
		/*	j++;
			}
			i = i + j;*/
			continue;
		}
		count += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
