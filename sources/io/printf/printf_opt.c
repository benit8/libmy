/*
** printf_opt.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO/printf
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Nov 21 14:36:22 2017 Benoit Lormeau
** Last update Tue Nov 21 14:36:22 2017 Benoit Lormeau
*/

#include "io.h"
#include "printf.h"

void printf_get_opt(const char **fmtp, va_list ap, printfOpt_t *opt)
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

void printf_get_opt_ap(va_list ap, printfOpt_t *opt)
{
	if (opt->prec)
		opt->precLen = va_arg(ap, int);
	else
		opt->padSize = va_arg(ap, int);
}

void printf_get_opt_fmt(const char **fmtp, printfOpt_t *opt)
{
	const char *t;
	char *str;

	for (t = (*fmtp); is_digit(*(*fmtp)); ++(*fmtp));
	str = str_ndup(t, (*fmtp) - t);
	if (opt->prec)
		opt->precLen = my_atoi(str);
	else
		opt->padSize = my_atoi(str);
	my_free(str);
	(*fmtp)--;
}

void printf_get_opt_num(const char **fmtp, char **tmpbuf, printfOpt_t *opt)
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