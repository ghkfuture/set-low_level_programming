#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: number to process
 * Return: value of last digit
 */
int print_last_digit(int n)
{
	int last_d;

	last_d = n % 10;
	if (last_d < 0)
		last_d = -last_d;
	_putchar(last_d + '0');
	return (last_d);
}
