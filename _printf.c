#include "main.h"

/**
 * _printf - produce output according to a format
 * @format: a character string composed of zero or more directives
 * @...: variable number of arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list args_list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args_list, format);

	while (*format)
	{
		checks_char(format, args_list, &char_print);
		format++;
	}

	va_end(args_list);

	return (char_print);
}

/**
 * checks_char - checks characters and format specifiers
 * @format: the format string
 * @args_list: list of arguments
 * @char_print: number of characters printed
 */
void checks_char(const char *format, va_list args_list, int *char_print)
{
	if (*format != '%')
	{
		write(1, format, 1);
		(*char_print)++;
	}
	else
	{
		format++;
		if (*format == '\0')
		{
			return;
		}
		checks_specifier(format, args_list, char_print);
	}
}

/**
 * checks_specifier - checks different format specifier
 * @format: the format string
 * @args_list: list of arguments
 * @char_print: number of characters printed
 */
void checks_specifier(const char *format, va_list args_list, int *char_print)
{
	if (*format == '%')
	{
		print_percent(char_print);
	}
	else if (*format == 'c')
	{
		char c = va_arg(args_list, int);

		print_char(c, char_print);
	}
	else if (*format == 's')
	{
		char *str = va_arg(args_list, char*);

		print_string(str, char_print);
	}
}
