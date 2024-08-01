#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int (*get_print_func(char c))(va_list);
int count_digits(int n);
char *int_to_str(int n, char *buffer);
int print_int(va_list args);

#endif /* MAIN_H */
