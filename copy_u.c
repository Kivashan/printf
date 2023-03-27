#include "main.h"

/**
 * copy_u - Prints each digit of variable i
 * @ap: va_arg agrument
 * @buffer: string to copy in
 * @bp: position of first empty string in buffer
 *
 * Return: total number of characters printed
 */

int copy_u(va_list ap, char *buffer, unsigned long int *bp)
{
	int count = 0;
	unsigned int i = (unsigned int)va_arg(ap, int);
	
	/* calls recursive function to print i */
	_put_number(i, buffer, bp, &count);

	return (count);
}
