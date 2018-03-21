/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** printf_print.c
*/

#include "my/io.h"
#include "printf.h"

void printf_print_char(char **tmpbuf, va_list ap)
{
	char c = va_arg(ap, int);

	(*tmpbuf) = str_napd(*tmpbuf, &c, 1);
}

void printf_print_str(char **tmpbuf, va_list ap, printf_opt_t opt)
{
	char *str = va_arg(ap, char *);

	if (!str)
		str = "(null)";
	if (opt.prec)
		(*tmpbuf) = str_napd(*tmpbuf, str, opt.prec_len);
	else
		(*tmpbuf) = str_apd(*tmpbuf, str);
}

void printf_print_numeric(const char **fmtp,
			char **tmpbuf,
			va_list ap,
			printf_opt_t *opt)
{
	size_t u = 0;
	ssize_t n = 0;
	char *str = NULL;

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
			printf_opt_t *opt)
{
	double d = 0.0;
	char *str = NULL;

	if (!opt->prec) {
		if (str_chr("gG", *(*fmtp)))
			opt->prec_len = 5;
		else
			opt->prec_len = 6;
	}
	d = va_arg(ap, double);
	str = my_ftoa(d, opt->prec_len);
	if (is_upper(*(*fmtp)))
		str = str_toupper(str);
	(*tmpbuf) = str_apd(*tmpbuf, str);
	my_free(str);
}