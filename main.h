#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct printer {
	char spec;
	 void (*case_func)(va_list, char *, int *);
}get;

int _printf(const char *format, ...);
void copy_char(va_list, char *, int *);
void copy_string(va_list, char *, int *);
void print_buffer(char *, int *);
int print_percent(char *, int *, char *, int *);

/*int _strlen(char *);
char *_strcpy(char *, char *);
int check_end_case(int, const char *);*/

#endif
