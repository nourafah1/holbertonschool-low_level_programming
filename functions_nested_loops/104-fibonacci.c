#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long a1 = 1, a2 = 0;
	unsigned long b1 = 2, b2 = 0;
	unsigned long c1, c2;
	int i;

	printf("1, 2");

	for (i = 3; i <= 98; i++)
	{
		c1 = a1 + b1;
		c2 = a2 + b2;

		if (c1 > 9999999999)
		{
			c2 += c1 / 10000000000;
			c1 %= 10000000000;
		}

		printf(", ");

		if (c2 > 0)
			printf("%lu%010lu", c2, c1);
		else
			printf("%lu", c1);

		a1 = b1;
		a2 = b2;
		b1 = c1;
		b2 = c2;
	}

	printf("\n");

	return (0);
}
