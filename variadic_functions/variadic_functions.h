#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct printer - matches a format with a function
 * @symbol: format symbol
 * @print: function to print
 */
typedef struct printer
{
	char symbol;
	void (*print)(va_list, char *);
} printer_t;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

void print_char(va_list arg, char *sep);
void print_int(va_list arg, char *sep);
void print_float(va_list arg, char *sep);
void print_string(va_list arg, char *sep);

#endif
