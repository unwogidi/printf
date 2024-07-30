#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int (*get_print_func(char c))(va_list);
int _printf(const char *format, ...);
int print_int(va_list args);

#endif /* MAIN_H */
