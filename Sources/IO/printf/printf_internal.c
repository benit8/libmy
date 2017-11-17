/*
** printf_internal.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO/printf
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Nov 14 10:28:33 2017 Benoit Lormeau
** Last update Tue Nov 14 11:50:59 2017 Benoit Lormeau
*/

#include "IO.h"

printfOpt_t printf_get_opt(const char **fmtp, va_list ap);

bool printf_process(const char **fmtp, char **buffp, va_list ap)
{
	printfOpt_t opt;
	const char *begin = (*fmtp)++;
	char *tmpbuf = my_calloc(64, sizeof(char));
	char *str;

	if (tmpbuf == NULL)
		return (false);
	opt = printf_get_opt(fmtp, ap);
	if (*(*fmtp) == '%')
		tmpbuf = str_apd(tmpbuf, "%");
	else if (*(*fmtp) == 'c'){
		char c = va_arg(ap, int);
		tmpbuf = str_napd(tmpbuf, &c, 1);
	}
	else if (*(*fmtp) == 's'){
		str = va_arg(ap, char *);
		str = (!str) ? "(null)" : str;
		if (opt.prec)
			tmpbuf = str_napd(tmpbuf, str, opt.precLen);
		else
			tmpbuf = str_apd(tmpbuf, str);
	}
	else {
		////////////////////////////////////////////////////////////////
		if (*(*fmtp) == 'l'){
			opt.longlong = true;
			if (*++(*fmtp) == 'l')
				++(*fmtp);
		}
		else if (*(*fmtp) == 'h')
			++(*fmtp);
		if (str_chr("bdiopxXu", *(*fmtp))){
			////////////////////////////////////////////////////////
			if (*(*fmtp) == 'u')
				opt.unsign = true;
			else if (*(*fmtp) == 'b')
				opt.base = 2;
			else if (*(*fmtp) == 'o')
				opt.base = 8;
			else if (*(*fmtp) == 'x' || *(*fmtp) == 'X')
				opt.base = 16;
			else if (*(*fmtp) == 'p'){
				opt.base = 16;
				opt.longlong = 1;
				tmpbuf = str_apd(tmpbuf, "0x");
			}

			////////////////////////////////////////////////////////
			if (opt.unsign || opt.base != 10){
				size_t u = va_arg(ap, size_t);
				str = my_utoa(u, opt.base);
			}
			else {
				ssize_t n = opt.longlong ? va_arg(ap, ssize_t) : va_arg(ap, int);
				str = my_itoa(n, opt.base);
			}

			if (opt.sign && opt.base == 10 && str[0] != '-')
				tmpbuf = str_apd(tmpbuf, "+");
			if (is_upper(*(*fmtp)))
				str = str_toupper(str);

			tmpbuf = str_apd(tmpbuf, str);
			my_free(str);
		}
		else if (str_chr("eEfgG", *(*fmtp))){
			////////////////////////////////////////////////////////
			if (!opt.prec){
				if (*(*fmtp) == 'g' || *(*fmtp) == 'G')
					opt.precLen = 5;
				else
					opt.precLen = 6;
			}

			double d = va_arg(ap, double);
			str = my_dtoa(d, opt.precLen);
			if (is_upper(*(*fmtp)))
				str = str_toupper(str);
			tmpbuf = str_apd(tmpbuf, str);
			my_free(str);
		}
		else
			*buffp = str_napd(*buffp, begin, (*fmtp) - begin + 1);
	}
	////////////////////////////////////////////////////////////////////////
	if (opt.padSize && !str_empty(tmpbuf)){
		char *old_tmpbuf = tmpbuf;
		switch (opt.align){
			case PRTF_RIGHT:
				tmpbuf = str_padl(tmpbuf, opt.padSize, " ");
			break;
			case PRTF_RIGHT0:
				tmpbuf = str_padl(tmpbuf, opt.padSize, "0");
			break;
			case PRTF_LEFT:
				tmpbuf = str_padr(tmpbuf, opt.padSize, " ");
			break;
			case PRTF_CENTER:
				tmpbuf = str_pad(tmpbuf, opt.padSize, " ");
			break;
		}
		my_free(old_tmpbuf);
	}

	*buffp = str_apd(*buffp, tmpbuf);
	my_free(tmpbuf);
	return (true);
}

printfOpt_t printf_get_opt(const char **fmtp, va_list ap)
{
	printfOpt_t opt = PRTF_OPT_DEF;
	char *str;
	const char *t;

	for (; *(*fmtp); ++(*fmtp)){
		if (!str_chr("-~.+*0123456789", *(*fmtp)))
			break;
		else if (*(*fmtp) == '-')
			opt.align = PRTF_LEFT;
		else if (*(*fmtp) == '0')
			opt.align = PRTF_RIGHT0;
		else if (*(*fmtp) == '~')
			opt.align = PRTF_CENTER;
		else if (*(*fmtp) == '.')
			opt.prec = true;
		else if (*(*fmtp) == '+')
			opt.sign = true;
		else if (*(*fmtp) == '*'){
			if (opt.prec)
				opt.precLen = va_arg(ap, int);
			else
				opt.padSize = va_arg(ap, int);
		}
		else if (str_chr("123456789", *(*fmtp))){
			for (t = (*fmtp); is_digit(*(*fmtp)); ++(*fmtp));
			str = str_ndup(t, (*fmtp) - t);
			if (opt.prec)
				opt.precLen = my_atoi(str);
			else
				opt.padSize = my_atoi(str);
			my_free(str);
			(*fmtp)--;
		}
	}
	return (opt);
}