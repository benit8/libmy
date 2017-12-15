/*
** io.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 13:52:54 2017 Benoit Lormeau
** Last update Tue Nov 14 11:54:54 2017 Benoit Lormeau
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "numeric.h"
#include "string.h"

////////////////////////////////////////////////////////////////////////////////

char	*gnl(const int fd);

void	my_putchar(char c);
void	my_putstr(const char *str);
void	my_putnbr(int nb);
void	my_puts(const char *str);

int	my_printf(const char *format, ...);
int	my_vprintf(const char *format, va_list ap);
int	my_dprintf(int fd, const char *format, ...);
int	my_vdprintf(int fd, const char *format, va_list ap);
int	my_sprintf(char *buff, const char *format, ...);
int	my_snprintf(char *buff, size_t max, const char *format, ...);
int	my_vsnprintf(char *buff, size_t max, const char *format, va_list ap);
int	my_vsprintf(char *buff, const char *format, va_list ap);
int	my_asprintf(char **strp, const char *format, ...);
int	my_vasprintf(char **strp, const char *format, va_list ap);