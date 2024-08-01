#include "main.h"

/**
 * print_char - print a character to stdout
 * @c: the character to print
 * @char_print: number of characters printed
 */
void print_char(char c, int *char_print)
{
	write(1, &c, 1);
	(*char_print)++;
}

/**
 * print_string - print a string to stdout
 * @str: the string to print
 * @char_print: number of characters printed
 */
void print_string(char *str, int *char_print)
{
	int _strlen = 0;

	while (str[_strlen] != '\0')
	{
		_strlen++;
	}

	write(1, str, _strlen);
	(*char_print) += _strlen;
}

/**
 * print_percent - print a percent sign tp stdout
 * @char_print: number of characters printed
 */
void print_percent(int *char_print)
{
	write(1, "%", 1);
	(*char_print)++;
}
