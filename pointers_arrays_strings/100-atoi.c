#include "main.h"

/**
 * _atoi - convert string to integer
 * @s: string
 * Return: integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && started == 0)
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (started == 1)
			break;
		i++;
	}

	return (num * sign);
}
