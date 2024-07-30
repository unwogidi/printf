#include "main.h"

/**
 * print_int - prints an integer
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	char buffer[12];
	char *ptr = &buffer[11];
	int is_negative = n < 0;

	*ptr = '\0';
	if (n == 0)
	{
		*--ptr = '0';
		count++;
	}
	else
	{
		if (is_negative)
		{
			n = -n;
		}
		while (n > 0)
		{
			*--ptr = '0' + (n % 10);
			n /= 10;
			count++;
		}
		if (is_negative)
		{
			*--ptr = '-';
			count++;
		}
	}

	while (*ptr)
	{
		_putchar(*ptr++);
	}
	return (count);
}
