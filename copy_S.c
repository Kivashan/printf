#include "main.h"
/**
 * copy_S - copy formated str
 * @p: argument pointer
 * @buffer: print buffer
 * @bp: buffer position
 *
 * Description: copy string formated with hex
 * Return: int
 */
int copy_S(va_list p, char *buffer, unsigned long int *bp)
{
	unsigned char *str, *tmp;
       	char *hex = "0123456789ABCDEF";
	int i, s, h, rem = 0, k = 0, len = 0, j = 0;

	str = va_arg(p, void *);
	if (!str)
	{
		j = copy_null(buffer, bp);
		return (j);
	}
	for (i = 0; str[i]; i++)
		len++;
	tmp = malloc(sizeof(char) * len + 5);
	if (!tmp)
		return (-1);
	for (i = 0; str[i]; i++)
	{
		j = null_byte_check(str[i], buffer, bp);
		if (str[i] > 127)
			i = i + 1;
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			tmp[j] = 92;
			j = j + 1;
			tmp[j] = 'x';
			j = j + 1;
			h = j + 1;
			k = str[i];
			for (s = 0; s < 2; s++, j++, h--)
			{
				rem = k % 16;
				k = k / 16;
				tmp[h] = hex[rem];
			}
		}
		else
		{
			tmp[j] = str[i];
			j++;
		}
	}
	for (i = 0; i < j; i++)
	{
		buffer_update(tmp[i], buffer, bp);
	}
	free(tmp);
	return (j);
}

int null_byte_check(char str, char *buffer, unsigned long int *bp)
{
	if (!str)
	{
		buffer_update('0', buffer, bp);
		return (1);
	}
	return(0);
}

void buffer_update(char c, char *buffer, unsigned long int *bp)
{
	buffer[*bp] = c;
	*bp += 1;
	check_buffer(buffer, bp);
}
