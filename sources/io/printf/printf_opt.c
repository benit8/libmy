/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** printf_opt.c
*/

#include "my/io.h"
#include "printf.h"

void printf_get_opt(const char **fmtp, va_list ap, printf_opt_t *opt)
{
	for (; *(*fmtp); ++(*fmtp)) {
		if (!my_strchr("-~.+*0123456789", *(*fmtp)))
			break;
		opt->align = (*(*fmtp) == '-') ? PRTF_LEFT : opt->align;
		opt->align = (*(*fmtp) == '0') ? PRTF_RIGHT0 : opt->align;
		opt->align = (*(*fmtp) == '~') ? PRTF_CENTER : opt->align;
		opt->prec = (*(*fmtp) == '.') ? true : opt->prec;
		opt->sign = (*(*fmtp) == '+') ? true : opt->sign;
		if (*(*fmtp) == '*')
			printf_get_opt_ap(ap, opt);
		else if (my_strchr("123456789", *(*fmtp)))
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
	str = my_strndup(t, (*fmtp) - t);
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
		(*tmpbuf) = my_strapd(*tmpbuf, "0x");
		break;
	}
}