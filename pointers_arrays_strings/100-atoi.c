#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string
 * Return: converted number
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (!started && s[i] == '-')
			sign *= -1;
		else if (!started && s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			if (sign == -1)
				result = result * 10 - (s[i] - '0');
			else
				result = result * 10 + (s[i] - '0');
		}
		else if (started)
			break;

		i++;
	}

	return (result);
}
