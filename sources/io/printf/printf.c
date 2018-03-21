/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** printf.c
*/

#include "my/io.h"
#include "printf.h"

int my_printf(const char *format, ...)
{
	va_list ap;
	int n;

	va_start(ap, format);
	n = my_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (n);
}

int my_vprintf(const char *format, va_list ap)
{
	return (my_vdprintf(STDOUT_FILENO, format, ap));
}