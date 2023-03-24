#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

typedef struct functions
{
	char * fs;
	(*fn)(char *);
} printer;

#endif
