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
	char *str = "(null)";
	int i;

	for (i = 0; str[i]; i++)
	{
		buffer[*bp] = str[i];
		*bp = *bp + 1;
		check_buffer(buffer, bp);
	}
	return (i);
}
