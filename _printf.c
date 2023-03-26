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
	int i, j, flag, count = 0;
	char ch, *s;

	va_start(ap, format);
	i = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i]  == '%')
		{
			if (format[i + 1] == '%')
			{
			      count += _putchar('%');
                              i = i + 2;
                              break;
			}

			j = 1;
			flag = 0;
			while (flag == 0 && format[i + j] != '\0')
			{
				switch (format[i + j])
				{
					case 'c':
						ch = va_arg(ap, int);
						count += _putchar(ch);
						flag = 1;
						break;
					/*case 'C':
                                                ch = va_arg(ap, int);
                                                count += _putchar(ch);
                                                i = i + 2;
                                                break;*/
					case 's':
						s = va_arg(ap, char *);
						if (!s)
							s = "(null)";
						count += _puts(s);
						flag = 1;
						break;
					/*case 'S':
                                                s = va_arg(ap, char *);
                                                if (!s)
                                                        s = "(null)";
                                                count += _puts(s);
                                                i = i + 2;
                                                break;*/
				/*	case '%':
						if (j == 1)
					
							count += _putchar('%');
					
						i = i + 2;
						break;*/
					default:
							/*count += _putchar('%');
							i = i + 1;*/
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
