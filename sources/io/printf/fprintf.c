/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** dprintf.c
*/

#include "io.h"
#include "printf.h"

int my_fprintf(FILE *fp, const char *format, ...)
{
	va_list ap;
	int n;

	va_start(ap, format);
	n = my_vfprintf(fp, format, ap);
	va_end(ap);
	return (n);
}

int my_vfprintf(FILE *fp, const char *format, va_list ap)
{
	char *buffer = my_calloc(512, sizeof(char));
	int chars;

	if (buffer == NULL)
		return (-1);
	for (; *format; ++format) {
		if (*format == '%' && str_chr(PRTF_CHARS, *(format + 1)))
			buffer = str_napd(buffer, format, 1);
		else if (printf_process(&format, &buffer, ap) == false) {
			my_free(buffer);
			return (-1);
		}
	}
	chars = str_len(buffer);
	if (fp)
		fwrite(buffer, sizeof(char), chars, fp);
	my_free(buffer);
	return (chars);
}