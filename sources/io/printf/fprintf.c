/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dprintf.c
*/

#include "my/io.h"
#include "printf.h"

int my_fprintf(FILE *fp, const char *format, ...)
{
	va_list ap;
	int n;

	va_start(ap, format);
	n = my_vdprintf(fileno(fp), format, ap);
	va_end(ap);
	return (n);
}

int my_vfprintf(FILE *fp, const char *format, va_list ap)
{
	return (my_vdprintf(fileno(fp), format, ap));
}