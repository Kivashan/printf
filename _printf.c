#include "main.h"
int _printf(const char * format,...)
{
	char *buffer;
	int i, j, flag = 0, count = 0; 
	unsigned long int buff_pos = 0;
	va_list ap;
	get print[] = {{"c", copy_char},{"s", copy_string},{NULL, NULL}};

	va_start(ap, format);
	if (!format)
		return (-1);
	buffer = malloc(1024);
	if (!buffer)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (print_percent(format, &i, buffer, &buff_pos))
			{
				count++;
				continue;
			}
			/* Try introducing a while loop here to travers through format till null char is reached*/

			j = 0;
			while (print[j].spec != NULL)
			{
				if (print[j].spec[0] == format[i + 1])
				{
					count += (*print[j].case_func)(ap, buffer, &buff_pos);
					i = i + 1;
					flag = 1;
					break;
				}
				j++;
			}
			if (flag == 0)
			{
				check_buffer(buffer, &buff_pos);
				buffer[buff_pos] = format[i];
				buff_pos++;
				count++;
			}
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
