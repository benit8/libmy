/*
** printf_print.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO/printf
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Nov 21 14:36:30 2017 Benoit Lormeau
** Last update Tue Nov 21 14:36:30 2017 Benoit Lormeau
*/

#include "io.h"
#include "printf.h"

void printf_print_char(char **tmpbuf, va_list ap)
{
	char c = va_arg(ap, int);

	(*tmpbuf) = str_napd(*tmpbuf, &c, 1);
}

void printf_print_str(char **tmpbuf, va_list ap, printfOpt_t opt)
{
	char *str = va_arg(ap, char *);

	if (!str)
		str = "(null)";
	if (opt.prec)
		(*tmpbuf) = str_napd(*tmpbuf, str, opt.precLen);
	else
		(*tmpbuf) = str_apd(*tmpbuf, str);
}

void printf_print_numeric(const char **fmtp,
			  char **tmpbuf,
			  va_list ap,
			  printfOpt_t *opt)
{
	size_t u;
	ssize_t n;
	char *str;

	if (opt->unsign || opt->base != 10) {
		u = va_arg(ap, size_t);
		str = my_utoa(u, opt->base);
	}
	else {
		n = (opt->longlong) ? va_arg(ap, ssize_t) : va_arg(ap, int);
		str = my_itoa(n, opt->base);
	}
	if (opt->sign && opt->base == 10 && str[0] != '-')
		(*tmpbuf) = str_apd(*tmpbuf, "+");
	if (is_upper(*(*fmtp)))
		str = str_toupper(str);
	(*tmpbuf) = str_apd(*tmpbuf, str);
	my_free(str);
}

void printf_print_float(const char **fmtp,
			char **tmpbuf,
			va_list ap,
			printfOpt_t *opt)
{
	double d;
	char *str;

	if (!opt->prec) {
		if (*(*fmtp) == 'g' || *(*fmtp) == 'G')
			opt->precLen = 5;
		else
			opt->precLen = 6;
	}
	d = va_arg(ap, double);
	str = my_ftoa(d, opt->precLen);
	if (is_upper(*(*fmtp)))
		str = str_toupper(str);
	(*tmpbuf) = str_apd(*tmpbuf, str);
	my_free(str);
}