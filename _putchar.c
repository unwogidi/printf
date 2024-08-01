#include "main.h"

/**
 * _putchar - writes a character to the stdout
 * @c: a character
 * Return: on error -1
 */
int _putchar(char c);
{
	return (write(1, &c, 1));
}
