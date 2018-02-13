/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** printf_opt.c
*/

#include "io.h"
#include "printf.h"

void printf_get_opt(const char **fmtp, va_list ap, printf_opt_t *opt)
{
	for (; *(*fmtp); ++(*fmtp)) {
		if (!str_chr("-~.+*0123456789", *(*fmtp)))
			break;
		else if (*(*fmtp) == '-')
			opt->align = PRTF_LEFT;
		else if (*(*fmtp) == '0')
			opt->align = PRTF_RIGHT0;
		else if (*(*fmtp) == '~')
			opt->align = PRTF_CENTER;
		else if (*(*fmtp) == '.')
			opt->prec = true;
		else if (*(*fmtp) == '+')
			opt->sign = true;
		else if (*(*fmtp) == '*')
			printf_get_opt_ap(ap, opt);
		else if (str_chr("123456789", *(*fmtp)))
			printf_get_opt_fmt(fmtp, opt);
	}
}

void printf_get_opt_ap(va_list ap, printf_opt_t *opt)
{
	if (opt->prec)
		opt->prec_len = va_arg(ap, int);
	else
		opt->pad_size = va_arg(ap, int);
}

void printf_get_opt_fmt(const char **fmtp, printf_opt_t *opt)
{
	const char *t = NULL;
	char *str = NULL;

	for (t = (*fmtp); is_digit(*(*fmtp)); ++(*fmtp));
	str = str_ndup(t, (*fmtp) - t);
	if (opt->prec)
		opt->prec_len = my_atoi(str);
	else
		opt->pad_size = my_atoi(str);
	my_free(str);
	(*fmtp)--;
}

void printf_get_opt_num(const char **fmtp, char **tmpbuf, printf_opt_t *opt)
{
	switch (*(*fmtp)) {
		case 'u':
			opt->unsign = true;
		break;
		case 'b':
			opt->base = 2;
		break;
		case 'o':
			opt->base = 8;
		break;
		case 'x':
		case 'X':
			opt->base = 16;
		break;
		case 'p':
			opt->base = 16;
			opt->longlong = 1;
			(*tmpbuf) = str_apd(*tmpbuf, "0x");
		break;
	}
}