#include <stdio.h>

/**
 * main - finds the largest prime factor of 612852475143
 *
 * Return: Always 0
 */

int main(void)
{
	long n = 612852475143;
	long factor = 2;
	long largest = 0;

	while (n != 1)
	{
		if (n % factor == 0)
		{
			largest = factor;
			n = n / factor;
		}
		else
		{
			factor++;
		}
	}

	printf("%ld\n", largest);

	return (0);
}
