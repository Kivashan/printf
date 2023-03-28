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
	for (i = 0; str[i]; i++)
		len++;
	tmp = malloc(sizeof(char) * len + 5);
	if (!tmp)
		return (-1);
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 127)
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
		buffer[*bp] = tmp[i];
		*bp = *bp + 1;
		check_buffer(buffer, bp);
	}
	free(tmp);
	return (j);
}
