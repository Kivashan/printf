#include "main.h"

int copy_octal(va_list ap, char * buffer, unsigned long int * bp)
{
	int len, i, rem, num, len2, n = va_arg(ap, int);
	char *str;
	
	num = n;

		for (; n != 0; n = n / 10)
		       len++;
		len2 = len;
		str = malloc(sizeof(char) * len + 1);
		if (!str)
			return (-1);
		if (n < 8)
		{
			str[0] = n;
		}
		else
		{
			for (; num > 7; num = num / 10)
			{
				rem = num % 8;
				str[len] = rem;
			}

		}
		for (i = 0; i < len2; i++)
		{
			check_buffer(buffer, bp);
			buffer[i] = str[i];
			*bp += 1;
		}
		print_buffer(buffer, bp);
		free(str);
	return (len2);
}





