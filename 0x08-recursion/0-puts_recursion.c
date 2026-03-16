#include "main.h"
/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: string to print
 */
void _puts_recursion(char *s)
{
main.h if (*s == '\0')
main.h {
main.h main.h _putchar('\n');
main.h main.h return;
main.h }
main.h _putchar(*s);
main.h _puts_recursion(s + 1);
}
