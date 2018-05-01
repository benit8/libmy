/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** printf_process.c
*/

#include "my/io.h"
#include "printf.h"

bool printf_process(const char **fmtp, char **buffp, va_list ap)
{
	printf_opt_t opt = PRTF_OPT_DFLT;
	const char *begin = (*fmtp)++;
	char *tmpbuf = my_calloc(64, sizeof(char));

	printf_get_opt(fmtp, ap, &opt);
	if (*(*fmtp) == '%')
		tmpbuf = my_strapd(tmpbuf, "%");
	else if (*(*fmtp) == 'c')
		printf_print_char(&tmpbuf, ap);
	else {
		if (*(*fmtp) == 's')
			printf_print_str(&tmpbuf, ap, opt);
		else if (!printf_process_numeric(fmtp, &tmpbuf, ap, &opt))
			*buffp = my_strnapd(*buffp, begin, (*fmtp) - begin + 1);
	}
	if (opt.pad_size && !my_strempty(tmpbuf))
		printf_process_padding(&tmpbuf, opt);
	*buffp = my_strapd(*buffp, tmpbuf);
	my_free(tmpbuf);
	return (true);
}

bool printf_process_numeric(const char **fmtp, char **tmpbuf, va_list ap,
	printf_opt_t *opt)
{
	if (*(*fmtp) == 'l') {
		opt->longlong = true;
		if (*++(*fmtp) == 'l')
			++(*fmtp);
	}
	else if (*(*fmtp) == 'h')
		++(*fmtp);
	if (my_strchr("bdiopxXu", *(*fmtp))) {
		printf_get_opt_num(fmtp, tmpbuf, opt);
		printf_print_numeric(fmtp, tmpbuf, ap, opt);
	}
	else if (my_strchr("eEfgG", *(*fmtp)))
		printf_print_float(fmtp, tmpbuf, ap, opt);
	else
		return (false);
	return (true);
}

void printf_process_padding(char **tmpbuf, printf_opt_t opt)
{
	char *orig = *tmpbuf;

	switch (opt.align) {
	case PRTF_RIGHT:
		(*tmpbuf) = my_strpadl(*tmpbuf, " ", opt.pad_size);
		break;
	case PRTF_RIGHT0:
		(*tmpbuf) = my_strpadl(*tmpbuf, "0", opt.pad_size);
		break;
	case PRTF_LEFT:
		(*tmpbuf) = my_strpadr(*tmpbuf, " ", opt.pad_size);
		break;
	case PRTF_CENTER:
		(*tmpbuf) = my_strpad(*tmpbuf, " ", opt.pad_size);
		break;
	}
	if (*tmpbuf != orig)
		my_free(orig);
}