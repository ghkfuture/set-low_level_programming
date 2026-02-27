#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 * Return: Always 0
 */
int main(void)
{
unsigned long int i, f1 = 1, f2 = 2, f1_l, f1_h, f2_l, f2_h, n_l, n_h;
unsigned long int carry = 1000000000;

for (i = 1; i <= 90; i++)
{
printf("%lu, ", f1);
n_l = f1 + f2;
f1 = f2;
f2 = n_l;
}
f1_h = f1 / carry;
f1_l = f1 % carry;
f2_h = f2 / carry;
f2_l = f2 % carry;
for (; i <= 98; i++)
{
if (f1_h != 0)
printf("%lu%09lu", f1_h, f1_l);
else
printf("%lu", f1_l);
if (i != 98)
printf(", ");
n_l = f1_l + f2_l;
n_h = f1_h + f2_h + (n_l / carry);
n_l %= carry;
f1_h = f2_h;
f1_l = f2_l;
f2_h = n_h;
f2_l = n_l;
}
printf("\n");
return (0);
}
