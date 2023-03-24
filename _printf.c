#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list ap;
	int flag, i, j, count = 0;

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
						count += _putchar(va_arg(ap, int));
						flag = 1;
						break;
					case 's':
						count += _puts(va_arg(ap, char *));
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
