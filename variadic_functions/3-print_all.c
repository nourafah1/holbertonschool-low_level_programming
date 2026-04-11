#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a char
 * @arg: argument list
 * @sep: separator
 */
void print_char(va_list arg, char *sep)
{
	printf("%s%c", sep, va_arg(arg, int));
}

/**
 * print_int - prints an int
 * @arg: argument list
 * @sep: separator
 */
void print_int(va_list arg, char *sep)
{
	printf("%s%d", sep, va_arg(arg, int));
}

/**
 * print_float - prints a float
 * @arg: argument list
 * @sep: separator
 */
void print_float(va_list arg, char *sep)
{
	printf("%s%f", sep, va_arg(arg, double));
}

/**
 * print_string - prints a string
 * @arg: argument list
 * @sep: separator
 */
void print_string(va_list arg, char *sep)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s%s", sep, str);
}

/**
 * print_all - prints anything
 * @format: list of types
 */
void print_all(const char * const format, ...)
{
	va_list arg;
	unsigned int i;
	printer_t p[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{0, NULL}
	};

	va_start(arg, format);
	i = 0;
	while (format && format[i])
	{
		if (format[i] == p[0].symbol)
			p[0].print(arg, "");
		if (format[i] == p[1].symbol)
			p[1].print(arg, ", ");
		i++;
	}
	printf("\n");
	va_end(arg);
}
