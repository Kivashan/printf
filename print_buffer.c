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
	int i;
	i = write(1, buffer, *buff_pos);
	if (i == -1)
		exit(-1);
	free(buffer);
	*buff_pos = 0;
}
