/*
** asprintf.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO/printf
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Nov 14 09:54:00 2017 Benoit Lormeau
** Last update Tue Nov 14 10:12:52 2017 Benoit Lormeau
*/

#include "io.h"
#include "printf.h"

int my_asprintf(char **strp, const char *format, ...)
{
	va_list ap;
	int n;

	va_start(ap, format);
	n = my_vasprintf(strp, format, ap);
	va_end(ap);
	return (n);
}

int my_vasprintf(char **strp, const char *format, va_list ap)
{
	int r = -1;
	int size;
	va_list ap2;

	va_copy(ap2, ap);
	size = my_vsnprintf(NULL, 0, format, ap2);
	if (size >= 0) {
		*strp = my_calloc(size + 1, sizeof(char));
		if (*strp == NULL)
			return (-1);
		r = my_vsnprintf(*strp, size, format, ap);
		if (r < 0) {
			my_free(*strp);
			*strp = NULL;
		}
	}
	else
		*strp = NULL;
	va_end(ap2);
	return (r);
}