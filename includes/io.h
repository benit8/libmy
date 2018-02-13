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

#include "numeric.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

#define BUFFER_SIZE	32

////////////////////////////////////////////////////////////////////////////////

ssize_t get_delim(char **buf, size_t *bufsiz, int delimiter, FILE *fp);
ssize_t get_line(char **buf, size_t *bufsiz, FILE *fp);

char *gnl(const int fd);
char *fgnl(FILE *fp);

void my_putchar(char c);
void my_putstr(const char *str);
void my_putnbr(int nb);
void my_puts(const char *str);


int my_printf(const char *format, ...)
	__attribute__ (( __format__(__printf__, 1, 2) ));
int my_vprintf(const char *format, va_list ap)
	__attribute__ ((__format__ (__printf__, 1, 0)));

int my_dprintf(int fd, const char *format, ...)
	__attribute__ ((__format__ (__printf__, 2, 3)));
int my_vdprintf(int fd, const char *format, va_list ap)
	__attribute__ ((__format__ (__printf__, 2, 0)));

int my_sprintf(char *buff, const char *format, ...)
	__attribute__ ((__format__ (__printf__, 2, 3)));
int my_snprintf(char *buff, size_t max, const char *format, ...)
	__attribute__ ((__format__ (__printf__, 3, 4)));

int my_vsprintf(char *buff, const char *format, va_list ap)
	__attribute__ ((__format__ (__printf__, 2, 0)));
int my_vsnprintf(char *buff, size_t max, const char *format, va_list ap)
	__attribute__ ((__format__ (__printf__, 3, 0)));

int my_asprintf(char **strp, const char *format, ...)
	__attribute__ ((__format__ (__printf__, 2, 3)));
int my_vasprintf(char **strp, const char *format, va_list ap)
	__attribute__ ((__format__ (__printf__, 2, 0)));