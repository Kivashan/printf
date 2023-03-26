#include "main.h"

/**
 * copy_string - copies va_arg to buffer string
 * @list: va_list argument
 * @buffer: buffer string to copy to
 * @buff_pos: Integer pointer to the buffer position
 *
 * Return: Void
 */

void copy_string(va_list list, char *buffer, int *buff_pos)
{
	char *str = va_arg(list, char *);
	int i;
	
	if (!str)
	{
		char *fail = "(null)";
		for (i = 0; fail[i]; i++)
		{
			buffer[buff_pos] = fail[i];
			buff_pos++;
		}
	}
	else
	{	for (i = 0; str[i]; i++)
		{
			buffer[buff_pos] = str[i];
			buff_pos++;
		}
	}
}

