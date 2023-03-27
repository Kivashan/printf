#include "main.h"

/**
 * _put_number - prints digits of variable i recursively
 * @i: Integer to print
 * @count: Pointer to an int, count keeps track of chars printed
 *
 * Return: Void
 */

void _put_number(unsigned int i, int *count)
{
	int j;

	j = i % 10;
	if (i > 9)
	{
		i = i / 10;
		_put_number(i, count);
	}
	*count = *count + 1;
	_putchar(j + 48);
}

/**
 * _putint - Prints each digit of variable i
 * @i: Integer to print
 *
 * Return: total number of characters printed
 */

int _putint(int i)
{
	int count = 0;

	/* prints minus sign if i < 0 */
	if (i < 0)
	{
		_putchar('-');
		count++;
		i = _abs(i);
	}
	
	/* calls recursive function to print i */
	_put_number(i, &count);

	return (count);
}

