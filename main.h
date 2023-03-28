#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct printer - structure containing two members
 * @spec: pointer to a character string
 * @case_func: function pointer
 *
 * Description: Structure containing two members
 */

typedef struct printer
{
	char *spec;
	int (*case_func)(va_list, char *, unsigned long int *);
} get;

int _printf(const char *format, ...);
int copy_char(va_list, char *, unsigned long int *);
int copy_string(va_list, char *, unsigned long int *);
int print_buffer(char *, unsigned long int *);
int print_percent(const char *, int *, char *, unsigned long int *);
void check_buffer(char *, unsigned long int *);
int get_specifier(va_list, const char *, int *, char *, unsigned long int *);
int _abs(int n);
int copy_int(va_list ap, char *buffer, unsigned long int *bp);
void _put_number(unsigned int i, char *buffer, unsigned long int *bp
	, int *count);
int copy_binary(va_list, char *, unsigned long int *);
int copy_u(va_list, char *, unsigned long int *);
int copy_hex(va_list, char *, unsigned long int *);
int copy_HEX(va_list, char *, unsigned long int *);
int copy_octal(va_list ap, char * buffer, unsigned long int * bp);

#endif
