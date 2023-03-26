#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

tyoedef struct printer [] = {
	{char spec, void (*case_func)(va_list, char *, int *)}
} print;

int _printf(const char *format, ...);

/*int _strlen(char *);
char *_strcpy(char *, char *);
int check_end_case(int, const char *);*/

#endif
