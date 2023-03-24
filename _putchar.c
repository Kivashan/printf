#include "main.h"

/**
 * _putchar - Prints a character to stdout
 * @c: character to print
 *
 * Return: The number of character/s printed
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
