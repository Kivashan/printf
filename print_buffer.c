#include "main.h"

/**
 * print_buffer - prints the buffer string
 * @buffer: buffer string to print
 * @buff_pos: buffer position in string, also is equal to length of buffer
 *
 * Return: The number of characters printed
 */

void print_buffer(char *buffer, unsigned long int *buff_pos)
{
	if (*buff_pos > 0)
	write(1, buffer, *buff_pos);

	free(buffer);
}
