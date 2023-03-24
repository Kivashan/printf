#include "main.h"

/**
 * _puts - Prints a string
 * @s: Pointer to a string
 *
 * Return: Number of characters printed
 */

int _puts(char *s)
{
	int i = 0;

	for (i = 0; s[i]; i++)
	{
		_putchar(s[i]);
	}

	return (i);
}
