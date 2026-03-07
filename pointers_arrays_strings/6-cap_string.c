#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string
 * Return: pointer to string
 */
char *cap_string(char *s)
{
	int i = 0;
	int cap = 1;

	while (s[i] != '\0')
	{
		if (cap && (s[i] >= 'a' && s[i] <= 'z'))
			s[i] = s[i] - 32;

		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
		    s[i] == ',' || s[i] == ';' || s[i] == '.' ||
		    s[i] == '!' || s[i] == '?' || s[i] == '"' ||
		    s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
			cap = 1;
		else
			cap = 0;

		i++;
	}

	return (s);
}
