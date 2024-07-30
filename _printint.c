#include "main.h"
#include <stdlib.h>

/**
 * count_digits - counts the number of digits in an integer
 * @n: the integer to count digits
 * Return: the number of digits
 */
int count_digits(int n)
{
	int digits = n <= 0 ? 1 : 0;

	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

/**
 * int_to_str - converts an integer to a string
 * @n: the integer to convert
 * @buffer: the buffer to store the string
 * Return: pointer to the start of the string in the buffer
 */
char *int_to_str(int n, char *buffer)
{
	char *ptr = buffer;
	int is_negative = n < 0;

	*ptr = '\0';
	if (n == 0)
	{
		*--ptr = '0';
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
		}
		if (is_negative)
		{
			*--ptr = '-';
		}
	}
	return (ptr);
}

/**
 * print_int - prints an integer
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	char *ptr;
	int digits = count_digits(n);
	char *buffer = malloc(digits + 1);

	if (!buffer)
	{
		return (0);
	}

	ptr = int_to_str(n, buffer + digits);

	while (*ptr)
	{
		_putchar(*ptr++);
		count++;
	}

	free(buffer);
	return (count);
}
