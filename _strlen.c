#include "main.h"

/**
 * _strlen - Entry point
 * @s: takes a pointer to a string as an argument
 *
 * Return: The string length as an int
 */

int _strlen(char *s) 
{
        int len = 0;

        while (s[len] != '\0')
                len++;

        return (len);
}
