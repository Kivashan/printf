#include "main.h"
/**
 * copy_null - copy "null" to buffer
 * @buffer: print buffer
 * @bp: pointer to buffer position var
 *
 * Description: copy null to buffer
 * Return: i
 */
int copy_null(char *buffer, unsigned long int *bp)
{
	char *str = "(nill)";
	int i;

	for (i = 0; str[i]; i++)
		buffer_update(str[i], buffer, bp);
	return (i);
}
