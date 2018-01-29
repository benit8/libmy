/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** printf_process.c
*/

#include "io.h"
#include "printf.h"

bool printf_process(
	const char **fmtp,
	char **buffp,
	va_list ap)
{
	printfOpt_t opt = PRTF_OPT_DFLT;
	const char *begin = (*fmtp)++;
	char *tmpbuf = my_calloc(64, sizeof(char));

	if (tmpbuf == NULL)
		return (false);
	printf_get_opt(fmtp, ap, &opt);
	if (*(*fmtp) == '%')
		tmpbuf = str_apd(tmpbuf, "%");
	else if (*(*fmtp) == 'c')
		printf_print_char(&tmpbuf, ap);
	else if (*(*fmtp) == 's')
		printf_print_str(&tmpbuf, ap, opt);
	else if (!printf_process_numeric(fmtp, &tmpbuf, ap, &opt))
		*buffp = str_napd(*buffp, begin, (*fmtp) - begin + 1);
	if (opt.padSize && !str_empty(tmpbuf))
		printf_process_padding(&tmpbuf, opt);
	*buffp = str_apd(*buffp, tmpbuf);
	my_free(tmpbuf);
	return (true);
}

bool printf_process_numeric(
	const char **fmtp,
	char **tmpbuf,
	va_list ap,
	printfOpt_t *opt)
{
	if (*(*fmtp) == 'l') {
		opt->longlong = true;
		if (*++(*fmtp) == 'l')
			++(*fmtp);
	}
	else if (*(*fmtp) == 'h')
		++(*fmtp);
	if (str_chr("bdiopxXu", *(*fmtp))) {
		printf_get_opt_num(fmtp, tmpbuf, opt);
		printf_print_numeric(fmtp, tmpbuf, ap, opt);
	}
	else if (str_chr("eEfgG", *(*fmtp)))
		printf_print_float(fmtp, tmpbuf, ap, opt);
	else
		return (false);
	return (true);
}

void printf_process_padding(char **tmpbuf, printfOpt_t opt)
{
	switch (opt.align) {
		case PRTF_RIGHT:
			(*tmpbuf) = str_padl(*tmpbuf, opt.padSize, " ");
		break;
		case PRTF_RIGHT0:
			(*tmpbuf) = str_padl(*tmpbuf, opt.padSize, "0");
		break;
		case PRTF_LEFT:
			(*tmpbuf) = str_padr(*tmpbuf, opt.padSize, " ");
		break;
		case PRTF_CENTER:
			(*tmpbuf) = str_pad(*tmpbuf, opt.padSize, " ");
		break;
	}
}