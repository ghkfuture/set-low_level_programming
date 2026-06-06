#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5.
 * @argc: Argument count.
 * @argv: Argument vector containing target username.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
char key[7];
int len, sum, idx;
long rand_num;
char *lookup = "A-CHRDw87lNSgDomeRovZCr2ZjsYwFscuPicHaiIobaUgbihwJg";

if (argc != 2)
return (1);

len = strlen(argv[1]);
key[0] = lookup[(len ^ 59) & 63];
for (idx = 0, sum = 0; idx < len; idx++)
sum += argv[1][idx];
key[1] = lookup[(sum ^ 79) & 63];
for (idx = 0, sum = 1; idx < len; idx++)
sum *= argv[1][idx];
key[2] = lookup[(sum ^ 85) & 63];
for (idx = 0, rand_num = argv[1][0]; idx < len; idx++)
{
if (argv[1][idx] > (char)rand_num)
rand_num = argv[1][idx];
}
srand(rand_num ^ 14);
key[3] = lookup[rand() & 63];
for (idx = 0, sum = 0; idx < len; idx++)
sum += (argv[1][idx] * argv[1][idx]);
key[4] = lookup[(sum ^ 239) & 63];
for (idx = 0, sum = 0; idx < argv[1][0]; idx++)
sum = rand();
key[5] = lookup[(sum ^ 229) & 63];
key[6] = '\0';
printf("%s", key);
return (0);
}
