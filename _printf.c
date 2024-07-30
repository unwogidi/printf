#include "main.h"

/**
 * print_char - prints a char
 * @args: va_list containing the char to print
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = (char) va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s)
	{
		while (*s)
		{
			_putchar(*s++);
			count++;
		}
	}
	else
	{
		char *nil = "(nil)";

		while (*nil)
		{
			_putchar(*nil++);
			count++;
		}
	}
	return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: va_list not used
 * Return: number of character printed
 */
int print_percent(va_list args)
{
	(void) args;
	_putchar('%');
	return (1);
}

/**
 * get_print_func - selects the correct function to perform the operation
 * @c: the specifier passed as argument
 * Return: pointer to the function that corresponds to the specifier
 */
int (*get_print_func(char c))(va_list)
{
	if (c == 'c')
	{
		return (print_char);
	}
	if (c == 's')
	{
		return (print_string);
	}
	if (c == '%')
	{
		return (print_percent);
	}
	return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: a character string composed of zero or more directives
 * @...: variable number of arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0;
	int count = 0;
	int (*func)(va_list);

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			func = get_print_func(format[i]);
			if (func)
			{
				count += func(args);
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		i++;
	}
	va_end(args);
	return (count);
}
