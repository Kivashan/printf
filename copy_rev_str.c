#include "main.h"
/**
 * copy_rev - copy reversed string
 * @p: va_list pointer
 * @buffer: pointer to buffer
 * @bp: buffer pointer
 *
 * Description: copy reversed string
 * Return: len
 */

int copy_rev(va_list p, char *buffer, unsigned long int *bp)
{
	char *str;
	char *tmp;
	int i, len = 0, j = 0;

	str = va_arg(p, char *);
	for (i = 0; str[i]; i++)
		len++;
	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (-1);
	for (i = len - 1; i >= 0; i--)
	{
		tmp[j] = str[i];
		j++;
	}
	for (i = 0; tmp[i]; i++)
	{
		buffer[*bp] = tmp[i];
		check_buffer(buffer, bp);
		*bp = *bp + 1;
	}
	free(tmp);
	return (len);
}
