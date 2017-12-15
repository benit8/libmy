/*
** printf.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO/printf
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Nov 14 09:48:21 2017 Benoit Lormeau
** Last update Tue Nov 14 09:49:47 2017 Benoit Lormeau
*/

#include "io.h"
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