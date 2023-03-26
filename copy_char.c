#include "main.h"

/**
 * copy_char - copy character from va_list argument to buffer string
 * @list: va_arg argument
 * @buffer: buffer string to copy to
 * @buff_pos: pointer to an integer that tracks buffer position
 *
 * Return: Void
 */

void copy_char(va_list list, char *buffer, int *buff_pos)
{
	char ch = va_arg(list, int);

	buffer[buff_pos++] = ch;
}
