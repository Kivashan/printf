#include "main.h"

void cpy(int k, unsigned char *tmp, int *h, int *j);
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
	int i, h, len = 0, j = 0;

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
		if (str[i] > 127)
			i = i + 1;
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			tmp[j++] = 92;
			tmp[j++] = 'x';
			h = j + 1;
			cpy(str[i], tmp, &h, &j);
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
	return (i);
}
/**
 * buffer_update - update buffer
 * @c: character
 * @buffer: print buffer
 * @bp: buffer position
 *
 * Description - update print buffer
 * Return: void
 */
void buffer_update(char c, char *buffer, unsigned long int *bp)
{
	buffer[*bp] = c;
	*bp += 1;
	check_buffer(buffer, bp);
}
/**
 * cpy - char to hex
 * @k: chacter
 * @tmp: hex string
 * @h: int * tracks tmp
 * @j: int * tracks buffer count
 *
 * Description: convert char to hex
 * Return: void
 */
void cpy(int k, unsigned char *tmp, int *h, int *j)
{
	int s, rem;
	char *hex = "0123456789ABCDEF";

	for (s = 0; s < 2; s++, *j += 1, *h -= 1)
	{
		rem = k % 16;
		k = k / 16;
		tmp[*h] = hex[rem];
	}
}
