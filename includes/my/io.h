/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** io.h
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "my/numeric.h"
#include "my/string.h"

////////////////////////////////////////////////////////////////////////////////

#define BUFFER_SIZE	32

#define PRINTF_ATTR(f, a) __attribute__((__format__(__printf__, f, a)))

////////////////////////////////////////////////////////////////////////////////

ssize_t my_getdelim(char **buf, size_t *bufsiz, int delimiter, FILE *fp);
ssize_t my_getline(char **buf, size_t *bufsiz, FILE *fp);

char *gnl(const int fd);
char *fgnl(FILE *fp);

void my_putchar(char c);
void my_putstr(const char *str);
void my_putnbr(int nb);
void my_puts(const char *str);

int my_printf(const char *format, ...)
	PRINTF_ATTR(1, 2);
int my_vprintf(const char *format, va_list ap)
	PRINTF_ATTR(1, 0);

int my_dprintf(int fd, const char *format, ...)
	PRINTF_ATTR(2, 3);
int my_vdprintf(int fd, const char *format, va_list ap)
	PRINTF_ATTR(2, 0);

int my_fprintf(FILE *fp, const char *format, ...)
	PRINTF_ATTR(2, 3);
int my_vfprintf(FILE *fp, const char *format, va_list ap)
	PRINTF_ATTR(2, 0);

int my_sprintf(char *buff, const char *format, ...)
	PRINTF_ATTR(2, 3);
int my_snprintf(char *buff, size_t max, const char *format, ...)
	PRINTF_ATTR(3, 4);

int my_vsprintf(char *buff, const char *format, va_list ap)
	PRINTF_ATTR(2, 0);
int my_vsnprintf(char *buff, size_t max, const char *format, va_list ap)
	PRINTF_ATTR(3, 0);

int my_asprintf(char **strp, const char *format, ...)
	PRINTF_ATTR(2, 3);
int my_vasprintf(char **strp, const char *format, va_list ap)
	PRINTF_ATTR(2, 0);