#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct printer {
	char spec;
	 void (*case_func)(va_list, char *, unsigned long int *);
}get;

int _printf(const char *format, ...);
void copy_char(va_list, char *, unsigned long int *);
void copy_string(va_list, char *,unsigned long int *);
void print_buffer(char *, unsigned long int *);
int print_percent(const char *, int *, char *, unsigned long int *);

/*int _strlen(char *);
char *_strcpy(char *, char *);
int check_end_case(int, const char *);*/

#endif
