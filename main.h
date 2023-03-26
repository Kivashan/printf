#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct printer {
	char spec;
	 void (*case_func)(va_list, char *, size_t *);
}get;

int _printf(const char *format, ...);
void copy_char(va_list, char *, size_t *);
void copy_string(va_list, char *, size_t *);
void print_buffer(char *, size_t);
int print_percent(const char *, int *, char *, size_t *);

/*int _strlen(char *);
char *_strcpy(char *, char *);
int check_end_case(int, const char *);*/

#endif
