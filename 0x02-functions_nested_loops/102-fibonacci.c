#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int i, j = 1, k = 2, next;

	for (i = 1; i <= 50; i++)
	{
		if (i == 50)
			printf("%ld\n", j);
		else
			printf("%ld, ", j);
		next = j + k;
		j = k;
		k = next;
	}
	return (0);
}
