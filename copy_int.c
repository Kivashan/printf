#include "main.h"

/**
 * _put_number - prints digits of variable i recursively
 * @i: Integer to print
 * @count: Pointer to an int, count keeps track of chars printed
 *
 * Return: Void
 */

void _put_number(unsigned int i, char *buffer, unsigned long int *bp, int *count)
{
	int j;

	j = i % 10;
	if (i > 9)
	{
		i = i / 10;
		_put_number(i, buffer, bp, count);
	}
	buffer[*bp] = (j + 48);
	*bp = *bp + 1;
	*count = *count + 1;
}

/**
 * _putint - Prints each digit of variable i
 * @i: Integer to print
 *
 * Return: total number of characters printed
 */

int copy_int(va_list ap, char *buffer, unsigned long int *bp)
{
	int count = 0;
	int i = va_arg(ap,int);

	/* prints minus sign if i < 0 */
	if (i < 0)
	{
		buffer[*bp] = '-';
		*bp = *bp + 1;
		count++;

		i = _abs(i);
	}
	
	/* calls recursive function to print i */
	_put_number(i, buffer, bp, &count);

	return (count);
}

