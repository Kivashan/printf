#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char);
int _puts(char *);

typedef struct functions
{
	char * fs;
	(*fn)(char *);
} printer;

#endif
