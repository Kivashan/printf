#include "main.h"

/**
 * buffer_update - update buffer
 * @c: character
 * @buffer: print buffer
 * @bp: buffer position
 *
 * Description - update print buffer
 * Return: void
 */
void buffer_update(char c, char *buffer, unsigned long int *bp)
{
	buffer[*bp] = c;
	*bp += 1;
	check_buffer(buffer, bp);
}
