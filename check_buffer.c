#include "main.h"

/**
 * check_buffer - checks if buffer if full, if true then prints buffer
 * frees the buffer and set buff_pos to 0
 * @buffer: Buffer string to check
 * @buff_pos: Position of next empty element in buffer
 *
 * Return: Void
 */

void check_buffer(char *buffer, unsigned long int *buff_pos)
{

	if (*buff_pos == 1024)
	{
		print_buffer(buffer, buff_pos);
		*buff_pos = 0;
	}
}
