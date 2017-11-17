/*
** IO.h for libmy in /mnt/data/Delivery/Perso/libmy/Includes
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Nov 9 13:52:54 2017 Benoit Lormeau
** Last update Tue Nov 14 11:54:54 2017 Benoit Lormeau
*/

#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "Numeric.h"
#include "String.h"

#define PRTF_CHARS	"-+~.*0123456789bcdefghilopsuxX%"
#define PRTF_OPT_DEF	(printfOpt_t){PRTF_RIGHT, 0, 0, 0, 10, 0, 0, 0}

typedef enum
{
  PRTF_RIGHT,
  PRTF_LEFT,
  PRTF_CENTER,
  PRTF_RIGHT0
}	printfAlign;

typedef struct	printfOpt
{
  printfAlign	align;
  bool		prec;
  int		precLen;
  int		padSize;
  int		base;
  bool		sign;
  bool		unsign;
  bool		longlong;
}		printfOpt_t;


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

bool	printf_process(const char **fmtp, char **buffp, va_list ap);