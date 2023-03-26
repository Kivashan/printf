#include "main.h"

/**
 * check_end_case - checks element after the % and before the '\0'
 * @i: position of % in string s
 * @s: format string
 *
 * Return: 0 if there are only numbers between % and '\0'
 * else returns 1;
 */

int check_end_case(int i, const char *s)
{
	int flag = 0;
	int j = i + 1;

	while (s[j] != '\0')
	{
		if (s[j] < '0' || s[j] > '9')
		{
			flag = 1;
			break;
		}
		j++;
	}
	return (flag);
}
