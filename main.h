#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
void checks_char(const char *format, va_list args_list, int *char_print);
void checks_specifier(const char *format, va_list args_list, int *char_print);
void print_char(char c, int *char_print);
void print_string(char *str, int *char_print);
void print_percent(int *char_print);

#endif /* MAIN_H */
