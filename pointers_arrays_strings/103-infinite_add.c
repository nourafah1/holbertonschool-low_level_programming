#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 * Return: pointer to result or 0 if it can't fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, carry = 0, sum;

	while (n1[i])
		i++;
	while (n2[j])
		j++;

	k = size_r - 1;
	r[k] = '\0';
	k--;

	i--;
	j--;

	while (i >= 0 || j >= 0 || carry)
	{
		if (k < 0)
			return (0);

		sum = carry;

		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		r[k--] = (sum % 10) + '0';
		carry = sum / 10;
	}

	k++;

	return (&r[k]);
}
