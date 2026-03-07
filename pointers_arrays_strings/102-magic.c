#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int n;
	int *p;
	char a[5];
	char *p2;
	p = (int *)a;
	p2 = (char *)p;
	p2[0] = 98;
	p2[1] = 0;
	p2[2] = 0;
	p2[3] = 0;
	p2[4] = 0;
	p[5] = 98;
	printf("a[2] = %d\n", a[2]);
	return (0);
}
