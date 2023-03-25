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
	char *check = "(null)";
	if (s[i] == '\0')
	{
		while (check[i] != '\0')
		{
			_putchar(check[i]);
			i++;
		}
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}

	return (i);
}
