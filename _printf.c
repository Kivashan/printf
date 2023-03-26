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
	int i, count = 0;
	char ch, *s;
	int flag = 1;

	va_start(ap, format);
	i = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i]  == '%' && format[i + 1] != '\0')
		{
			flag = check_end_case(i, format);
			if (flag == 0)
				break;

			if (format[i + 1] == '%')
			{
			      count += _putchar('%');
                              i = i + 2;
                              break;
			}

					
				switch (format[i + 1])
				{
					case 'c':
						ch = va_arg(ap, int);
						count += _putchar(ch);
						i = i + 2;
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
						i = i + 2;
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
							count += _putchar('%');
							i = i + 1;
							break;
				}
					
			continue;
		}
		if ((format[i] == '%' && format[i + 1] == '\0') || flag == 0)
			return (-1);
		count += _putchar(format[i]);
		i++;
	}
	va_end(ap);

	return (count);
}
