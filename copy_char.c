#include "main.h"

/**
 * copy_char - copy character from va_list argument to buffer string
 * @list: va_arg argument
 * @buffer: buffer string to copy to
 * @buff_pos: pointer to an integer that tracks buffer position
 *
 * Return: Void
 */

int copy_char(va_list list, char *buffer, unsigned long int *buff_pos)
{
	char ch;

	ch = va_arg(list, int);
	
	check_buffer(buffer, buff_pos);

	buffer[*buff_pos] = ch;
	*buff_pos = *buff_pos + 1;
	return (1);
}
