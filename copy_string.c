#include "main.h"

/**
 * copy_string - copies va_arg to buffer string
 * @list: va_list argument
 * @buffer: buffer string to copy to
 * @buff_pos: Integer pointer to the buffer position
 *
 * Return: Void
 */

int copy_string(va_list list, char *buffer, unsigned long int *buff_pos)
{
	char *str = va_arg(list, char *);
	int i;
	int count = 0;

	if (!str)
	{
		count = copy_null(buffer, buff_pos);
	}
	else
	{
		for (i = 0; str[i]; i++)
		{
			check_buffer(buffer, buff_pos);
			buffer[*buff_pos] = str[i];
			*buff_pos = *buff_pos + 1;
			count++;
		}
	}
	return (count);
}

