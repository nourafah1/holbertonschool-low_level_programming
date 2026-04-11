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
	unsigned int i = 0, j;
	char *sep = "";
	char types[] = {'c', 'i', 'f', 's'};
	void (*funcs[])(va_list, char *) = {
		print_char, print_int, print_float, print_string
	};

	/* 🔥 هذا السطر الفاضي المهم */

	va_start(arg, format);
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == types[j])
			{
				funcs[j](arg, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(arg);
}
