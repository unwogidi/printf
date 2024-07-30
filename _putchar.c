#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes on the stdout
 * @c: a character
 * Return: 1 Success or -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
