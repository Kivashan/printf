#include "main.h"

/**
 * print_percent - checks if %% exist at i in format string
 * copies % to buffer if true
 * @fmt: format string
 * @i: pointer to intger I
 * @buffer: string to copy to
 * @bp: pointer to buffer position
 *
 * Return: 1 if %%, 0 otherwise
 */

int print_percent(const char *fmt, int *i, char *buffer, unsigned long int *bp)
{

	if (fmt[*i + 1] == '%')
	{
		buffer_update(fmt[*i + 1], buffer, bp);
		*i += 1;
		return (1);
	}
	return (0);
}
