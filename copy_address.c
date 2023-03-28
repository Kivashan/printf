#include "main.h"

/**
 * copy_address - copies the address of a variable into the buffer string
 * @ap: va_arg argument
 * @buffer: string to copy into
 * @bp: position of first empty element in buffer
 *
 * Return: number of characters copied in buffer
 */

int copy_address(va_list ap, char *buffer, unsigned long int *bp)
{
	char *prefix = "0x";
	int i = 0, j;
	
	for (i = 0; prefix[i]; i++)
	{
		buffer[*bp] = prefix[i];
		*bp = *bp + 1;
		check_buffer(buffer, bp);
	}
	j = 2;
	j += copy_ax(ap, buffer, bp);

	return (j);
}
