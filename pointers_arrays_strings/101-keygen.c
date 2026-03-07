#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
	int sum = 0;
	int n;
	char c;

	srand(time(0));

	while (sum < 2645)
	{
		n = rand() % 78 + 48;
		if ((sum + n) > 2772)
			break;
		sum += n;
		printf("%c", n);
	}

	c = 2772 - sum;
	printf("%c", c);

	return (0);
}
