#include "main.h"

/**
 * rot_13 - copies string in a rot_13 emcryption, into buffer
 * @ap: va_arg argument
 * @buffer: string to copy into
 * @bp: position of first empty element in buffer
 *
 * Return: number of characters copied into buffer
 */

int rot_13(va_list ap, char *buffer, unsigned long int *bp)
{
	char *str = va_arg(ap, char *);
	char *rot1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot2 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j, flag = 0;
	char tmp;

	if (!str)
	{
		int i;
		char *fail = "(null)";

		for (i = 0; fail[i]; i++)
		{
			buffer[*bp] = fail[i];
			*bp = *bp + 1;
			check_buffer(buffer, bp);
		}
		return (i);
	}
	
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; rot1[j] != '\0'; j++)
		{
			if (str[i] == rot1[j])
			{
				tmp = rot2[j];
				flag = 1;
				break;
			}
			flag = 0;
		}
		buffer[*bp] = (flag == 1) ? tmp : str[i];
		*bp = *bp + 1;
		check_buffer(buffer, bp);
	}
	return (i);
}
