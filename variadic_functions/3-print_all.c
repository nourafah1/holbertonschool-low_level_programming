#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a char
 * @args: argument list
 * @sep: separator
 */
void print_char(va_list args, char *sep)
{
	printf("%s%c", sep, va_arg(args, int));
}

/**
 * print_int - prints an int
 * @args: argument list
 * @sep: separator
 */
void print_int(va_list args, char *sep)
{
	printf("%s%d", sep, va_arg(args, int));
}

/**
 * print_float - prints a float
 * @args: argument list
 * @sep: separator
 */
void print_float(va_list args, char *sep)
{
	printf("%s%f", sep, va_arg(args, double));
}

/**
 * print_string - prints a string
 * @args: argument list
 * @sep: separator
 */
void print_string(va_list args, char *sep)
{
	char *str;

	str = va_arg(args, char *);
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
	va_list args;
	unsigned int i = 0;
	unsigned int j;
	char *sep = "";
	char types[] = {'c', 'i', 'f', 's'};
	void (*funcs[])(va_list, char *) = {
		print_char,
		print_int,
		print_float,
		print_string
	};

	va_start(args, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == types[j])
			{
				funcs[j](args, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
