/*
** dprintf.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/IO
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Nov 7 22:03:18 2017 Benoit Lormeau
** Last update Tue Nov 7 22:03:18 2017 Benoit Lormeau
*/

#include "IO.h"
#include <stdio.h>

int my_printf(const char *format, ...)
{
	va_list ap;
	int n;

	va_start(ap, format);
	n = my_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (n);
}

int my_vprintf(const char *format, va_list ap)
{
	return (my_vdprintf(STDOUT_FILENO, format, ap));
}

int my_dprintf(int fd, const char *format, ...)
{
	va_list ap;
	int n;

	va_start(ap, format);
	n = my_vdprintf(fd, format, ap);
	va_end(ap);
	return (n);
}


ssize_t convert(ssize_t n, int base)
{
	base = ABS(base);
	if (n == 0 || base == 10)
		return (n);
	return (n % base) + 10 * convert(n / base, base);
}
size_t uconvert(size_t n, int base)
{
	base = ABS(base);
	if (n == 0 || base == 10)
		return (n);
	return (n % base) + 10 * convert(n / base, base);
}


int my_vdprintf(int fd, const char *format, va_list ap)
{
	register const char *f = format;
	char *buffer = my_calloc(256, sizeof(char));
	char *tmpbuf = my_calloc(32, sizeof(char));
	char *buff = buffer;
	char *str_nb;
	printfOpt_t opt;

	if (buffer == NULL || tmpbuf == NULL)
		return (-1);
	for (; *f; ++f){
		if (*f == '%'){
			if (!str_chr("-~+.*0123456789bcdefgilopPrRsuxX%", *(f + 1)))
				continue;
			f++;
			opt = (printfOpt_t){PRTF_RIGHT, false, 0, 0, 10, false, false, false};
			my_memset(tmpbuf, 0, my_malloc_size(tmpbuf));
			for (; *f; ++f){
				if (str_chr("bcdefgilopPrRsuxX%", *f))
					break;
				else if (*f == '-')
						opt.align = PRTF_LEFT;
				else if (*f == '0')
						opt.align = PRTF_RIGHT0;
				else if (*f == '~')
						opt.align = PRTF_CENTER;
				else if (*f == '.')
						opt.prec = true;
				else if (*f == '+')
						opt.sign = true;
				else if (*f == '*'){
					if (opt.prec)
						opt.precLen = va_arg(ap, int);
					else
						opt.padSize = va_arg(ap, int);
				}
				else if (*f >= '1' && *f <= '9'){
					const char *t;
					for (t = f; is_digit(*f); ++f);
					str_nb = str_ndup(t, f - t);
					if (opt.prec)
						opt.precLen = my_atoi(str_nb);
					else
						opt.padSize = my_atoi(str_nb);
					my_free(str_nb);
					--f;
				}
			}
			if (*f == '%')
				tmpbuf = str_apd(tmpbuf, "%");
			else if (*f == 'c'){
				char c = va_arg(ap, int);
				tmpbuf = str_napd(tmpbuf, &c, 1);
			}
			else if (*f == 's'){
				char *str = va_arg(ap, char *);
				if (opt.prec)
					tmpbuf = str_napd(tmpbuf, str ? str : "(null)", opt.precLen);
				else
					tmpbuf = str_apd(tmpbuf, str ? str : "(null)");
			}
			else {
				if (*f == 'l' && *++f == 'l'){
					opt.longlong = true;
					f++;
				}
				if (str_chr("bdiopPrRxXu", *f)){
					if (*f == 'u')
						opt.unsign = true;
					else if (*f == 'b')
						opt.base = 2;
					else if (*f == 'o')
						opt.base = 8;
					else if (*f == 'x' || *f == 'X')
						opt.base = 16;
					else if (*f == 'p'){
						opt.align = PRTF_RIGHT0;
						opt.base = 16;
						opt.padSize = 16;
						opt.longlong = 1;
						tmpbuf = str_apd(tmpbuf, "0x");
					}

					if (opt.unsign){
						size_t u = va_arg(ap, size_t);
						u = uconvert(u, opt.base);
						str_nb = my_utoa(u);
					}
					else {
						int n = va_arg(ap, int);
						n = convert(n, opt.base);
						str_nb = my_itoa(n);
					}
					tmpbuf = str_apd(tmpbuf, str_nb);
					my_free(str_nb);
				}
			}

			if (opt.padSize){
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

			buff = str_apd(buff, tmpbuf);
		}
		else {
			buff = str_napd(buff, f, 1);
		}
	}

	int chars = str_len(buffer);
	if (fd >= 0)
		write(fd, buffer, chars);
	my_free(buffer);
	my_free(tmpbuf);
	return (chars);
}


// int vsprintf (char *d, const char *s, va_list ap)
// {
// 	const char *t;
// 	char *p, *dst, tmp[40];
// 	unsigned int n;
// 	int fmt, trunc, haddot, width, base, longlong;

// 	dst = d;
// 	for (; *s;) {						// parcours format
// 		if (*s == '%') {					// if encounter format specifier
// 			s++;
// 			fmt = FMT_RJUST;					// default align is right
// 			width = trunc = haddot = longlong = 0;			// reset options
// 			for (; *s; s++) {					// parcour, looking for options
// 				if (strchr("bcdefgilopPrRsuxX%", *s))		// if specifier is directly found
// 					break;					//   => no options
// 				else if (*s == '-')				// left align: '%-5d', 43
// 					fmt = FMT_LJUST;			//  = '   43'
// 				else if (*s == '0')				// pad with 0s: '%05d', 43
// 					fmt = FMT_RJUST0;			//  = '00043'
// 				else if (*s == '~')				// align center: '%~5d', 43
// 					fmt = FMT_CENTER;			//  = ' 43  '
// 				else if (*s == '*'){				// variable pad/precision length
// 					if (haddot)
// 						trunc = va_arg(ap, int);
// 					else
// 						width = va_arg(ap, int);
// 				}
// 				else if (*s >= '1' && *s <= '9'){		// '%12d'
// 					for (t = s; isdigit(*s); s++);
// 					strncpy(tmp, t, s - t);
// 					tmp[s - t] = '\0';
// 					atob(&n, tmp, 10);			// some getnbr_base
// 					if (haddot)
// 						trunc = n;
// 					else
// 						width = n;
// 					s--;					// prevent skipping 1 char
// 				}
// 				else if (*s == '.'){				// precision: '%.3f'
// 					haddot = 1;
// 					trunc = 3;
// 				}
// 			}
// 			if (*s == '%') {
// 				*d++ = '%';
// 				*d = 0;
// 			} else if (*s == 's') {
// 				p = va_arg(ap, char *);

// 				if (p)
// 					strcpy(d, p);
// 				else
// 					strcpy(d, "(null)");
// 			} else if (*s == 'c') {
// 				n = va_arg (ap, int);
// 				*d = n;
// 				d[1] = 0;
// 			} else {
// 				if (*s == 'l') {
// 					if (*++s == 'l') {
// 						longlong = 1;
// 						++s;
// 					}
// 				}
// 				if (strchr("bdiopPrRxXu", *s)){
// 					if (*s == 'd' || *s == 'i')
// 						base = -10;
// 					else if (*s == 'u')
// 						base = 10;
// 					else if (*s == 'x' || *s == 'X')
// 						base = 16;
// 					else if(*s == 'p' || *s == 'P') {
// 						base = 16;
// 						if (*s == 'p') {
// 							*d++ = '0';
// 							*d++ = 'x';
// 						}
// 						fmt = FMT_RJUST0;
// 						if (sizeof(long) > 4) {
// 							width = 16;
// 							longlong = 1;
// 						} else {
// 							width = 8;
// 						}
// 					}
// 					else if(*s == 'r' || *s == 'R') {
// 						base = 16;
// 						if (*s == 'r') {
// 							*d++ = '0';
// 							*d++ = 'x';
// 						}
// 						fmt = FMT_RJUST0;
// 						if (sizeof(register_t) > 4) {
// 							width = 16;
// 							longlong = 1;
// 						} else {
// 							width = 8;
// 						}
// 					}
// 					else if (*s == 'o')
// 						base = 8;
// 					else if (*s == 'b')
// 						base = 2;
// 					if (longlong)
// 						llbtoa(d, va_arg (ap, quad_t), base);
// 					else
// 						btoa(d, va_arg (ap, int), base);

// 					if (*s == 'X')
// 						strtoupper(d);
// 				}
// 				else if (strchr ("eEfgG", *s)){
// 					dbl = va_arg(ap, double);
// 					dtoa(d, dbl, *s, width, trunc);
// 					trunc = 0;
// 				}
// 			}
// 			if (trunc)
// 				d[trunc] = 0;
// 			if (width)
// 				str_fmt (d, width, fmt);
// 			for (; *d; d++);
// 			s++;
// 		} else
// 			*d++ = *s++;
// 	}
// 	*d = 0;
// 	return (d - dst);
// }

// #ifdef FLOATINGPT


// #define MAX_FCONVERSION	512	/* largest possible real conversion 	*/
// #define MAX_FRACT	39	/* largest possible fraction field */

// #define TESTFLAG(x)	0


// typedef double rtype;

// extern double modf(double, double *);
// #define	to_char(n)	((n) + '0')
// #define	to_digit(c)	((c) - '0')
// #define _isNan(arg)	((arg) != (arg))

// static int cvt (rtype arg, int prec, char *signp, int fmtch, char *startp, char *endp);
// static char *round (double fract, int *exp, char *start, char *end, char ch, char *signp);
// static char *exponent(char *p, int exp, int fmtch);


// /*
//  * _finite arg not Infinity or Nan
//  */
// static int _finite(rtype d)
// {
// #if ENDIAN == ENDIAN_LITTLE
//     struct IEEEdp {
// 	unsigned manl:32;
// 	unsigned manh:20;
// 	unsigned exp:11;
// 	unsigned sign:1;
//     } *ip;
// #else
//     struct IEEEdp {
// 	unsigned sign:1;
// 	unsigned exp:11;
// 	unsigned manh:20;
// 	unsigned manl:32;
//     } *ip;
// #endif

//     ip = (struct IEEEdp *)&d;
//     return (ip->exp != 0x7ff);
// }



// void str_fmt(char *p, int size, int fmt)
// {
// 	int n, m, len;

// 	len = strlen(p);
// 	switch (fmt) {
// 		case FMT_RJUST:
// 			for (n = size - len; n > 0; n--)
// 				strichr(p, ' ');
// 		break;
// 		case FMT_LJUST:
// 			for (m = size - len; m > 0; m--)
// 				strcat(p, " ");
// 		break;
// 		case FMT_RJUST0:
// 			for (n = size - len; n > 0; n--)
// 				strichr(p, '0');
// 		break;
// 		case FMT_CENTER:
// 			m = (size - len) / 2;
// 			n = size - (len + m);
// 			for (; m > 0; m--)
// 				strcat(p, " ");
// 			for (; n > 0; n--)
// 				strichr(p, ' ');
// 		break;
// 	}
// }

// static void dtoa (char *dbuf, rtype arg, int fmtch, int width, int prec)
// {
// 	char	buf[MAX_FCONVERSION+1], *cp;
// 	char	sign;
// 	int	size;

// 	if( !_finite(arg) ) {
// 		if( _isNan(arg) )
// 			strcpy (dbuf, "NaN");
// 		else if( arg < 0)
// 			strcpy (dbuf, "-Infinity");
// 		else
// 			strcpy (dbuf, "Infinity");
// 		return;
// 	}

// 	if (prec == 0)
// 		prec = 6;
// 	else if (prec > MAX_FRACT)
// 		prec = MAX_FRACT;

// 	/* leave room for sign at start of buffer */
// 	cp = buf + 1;

//     /*
//      * cvt may have to round up before the "start" of
//      * its buffer, i.e. ``intf("%.2f", (double)9.999);'';
//      * if the first character is still NUL, it did.
//      * softsign avoids negative 0 if _double < 0 but
//      * no significant digits will be shown.
//      */
// 	*cp = '\0';
// 	size = cvt (arg, prec, &sign, fmtch, cp, buf + sizeof(buf));
// 	if (*cp == '\0')
// 		cp++;

// 	if (sign)
// 		*--cp = sign, size++;

// 	cp[size] = 0;
// 	memcpy (dbuf, cp, size + 1);
// }


// static int cvt(rtype number, int prec, char *signp, int fmtch, char *startp, char *endp)
// {
// 	register char *p, *t;
// 	register double fract;
// 	double integer, tmp;
// 	int dotrim, expcnt, gformat;

// 	dotrim = expcnt = gformat = 0;
// 	if (number < 0) {
// 		number = -number;
// 		*signp = '-';
// 	} else
// 		*signp = 0;

// 	fract = modf(number, &integer);

// 	/* get an extra slot for rounding. */
// 	t = ++startp;

// 	/*
// 	 * get integer portion of number; put into the end of the buffer; the
// 	 * .01 is added for modf(356.0 / 10, &integer) returning .59999999...
// 	 */
// 	for (p = endp - 1; integer; ++expcnt) {
// 		tmp = modf(integer / 10, &integer);
// 		*p-- = to_char((int)((tmp + .01) * 10));
// 	}
// 	switch (fmtch) {
// 	case 'f':
// 		/* reverse integer into beginning of buffer */
// 		if (expcnt)
// 			for (; ++p < endp; *t++ = *p);
// 		else
// 			*t++ = '0';
// 		/*
// 		 * if precision required or alternate flag set, add in a
// 		 * decimal point.
// 		 */
// 		if (prec || TESTFLAG(ALTERNATE_FORM))
// 			*t++ = '.';
// 		/* if requires more precision and some fraction left */
// 		if (fract) {
// 			if (prec)
// 				do {
// 					fract = modf(fract * 10, &tmp);
// 					*t++ = to_char((int)tmp);
// 				} while (--prec && fract);
// 			if (fract)
// 				startp = round(fract, (int *)NULL, startp,
// 				    t - 1, (char)0, signp);
// 		}
// 		for (; prec--; *t++ = '0');
// 		break;
// 	case 'e':
// 	case 'E':
// eformat:	if (expcnt) {
// 			*t++ = *++p;
// 			if (prec || TESTFLAG(ALTERNATE_FORM))
// 				*t++ = '.';
// 			/* if requires more precision and some integer left */
// 			for (; prec && ++p < endp; --prec)
// 				*t++ = *p;
// 			/*
// 			 * if done precision and more of the integer component,
// 			 * round using it; adjust fract so we don't re-round
// 			 * later.
// 			 */
// 			if (!prec && ++p < endp) {
// 				fract = 0;
// 				startp = round((double)0, &expcnt, startp,
// 				    t - 1, *p, signp);
// 			}
// 			/* adjust expcnt for digit in front of decimal */
// 			--expcnt;
// 		}
// 		/* until first fractional digit, decrement exponent */
// 		else if (fract) {
// 			/* adjust expcnt for digit in front of decimal */
// 			for (expcnt = -1;; --expcnt) {
// 				fract = modf(fract * 10, &tmp);
// 				if (tmp)
// 					break;
// 			}
// 			*t++ = to_char((int)tmp);
// 			if (prec || TESTFLAG(ALTERNATE_FORM))
// 				*t++ = '.';
// 		}
// 		else {
// 			*t++ = '0';
// 			if (prec || TESTFLAG(ALTERNATE_FORM))
// 				*t++ = '.';
// 		}
// 		/* if requires more precision and some fraction left */
// 		if (fract) {
// 			if (prec)
// 				do {
// 					fract = modf(fract * 10, &tmp);
// 					*t++ = to_char((int)tmp);
// 				} while (--prec && fract);
// 			if (fract)
// 				startp = round(fract, &expcnt, startp,
// 				    t - 1, (char)0, signp);
// 		}
// 		/* if requires more precision */
// 		for (; prec--; *t++ = '0');

// 		/* unless alternate flag, trim any g/G format trailing 0's */
// 		if (gformat && !TESTFLAG(ALTERNATE_FORM)) {
// 			while (t > startp && *--t == '0');
// 			if (*t == '.')
// 				--t;
// 			++t;
// 		}
// 		t = exponent(t, expcnt, fmtch);
// 		break;
// 	case 'g':
// 	case 'G':
// 		/* a precision of 0 is treated as a precision of 1. */
// 		if (!prec)
// 			++prec;
// 		/*
// 		 * ``The style used depends on the value converted; style e
// 		 * will be used only if the exponent resulting from the
// 		 * conversion is less than -4 or greater than the precision.''
// 		 *	-- ANSI X3J11
// 		 */
// 		if (expcnt > prec || (!expcnt && fract && fract < .0001)) {
// 			/*
// 			 * g/G format counts "significant digits, not digits of
// 			 * precision; for the e/E format, this just causes an
// 			 * off-by-one problem, i.e. g/G considers the digit
// 			 * before the decimal point significant and e/E doesn't
// 			 * count it as precision.
// 			 */
// 			--prec;
// 			fmtch -= 2;		/* G->E, g->e */
// 			gformat = 1;
// 			goto eformat;
// 		}
// 		/*
// 		 * reverse integer into beginning of buffer,
// 		 * note, decrement precision
// 		 */
// 		if (expcnt)
// 			for (; ++p < endp; *t++ = *p, --prec);
// 		else
// 			*t++ = '0';
// 		/*
// 		 * if precision required or alternate flag set, add in a
// 		 * decimal point.  If no digits yet, add in leading 0.
// 		 */
// 		if (prec || TESTFLAG(ALTERNATE_FORM)) {
// 			dotrim = 1;
// 			*t++ = '.';
// 		}
// 		else
// 			dotrim = 0;
// 		/* if requires more precision and some fraction left */
// 		if (fract) {
// 			if (prec) {
// 			        do {
// 				    fract = modf(fract * 10, &tmp);
// 				    *t++ = to_char((int)tmp);
// 				} while(!tmp && !expcnt);
// 				while (--prec && fract) {
// 					fract = modf(fract * 10, &tmp);
// 					*t++ = to_char((int)tmp);
// 				}
// 			}
// 			if (fract)
// 				startp = round(fract, (int *)NULL, startp,
// 				    t - 1, (char)0, signp);
// 		}
// 		/* alternate format, adds 0's for precision, else trim 0's */
// 		if (TESTFLAG(ALTERNATE_FORM))
// 			for (; prec--; *t++ = '0');
// 		else if (dotrim) {
// 			while (t > startp && *--t == '0');
// 			if (*t != '.')
// 				++t;
// 		}
// 	}
// 	return (t - startp);
// }


// static char *
// round(double fract, int *exp, char *start, char *end, char ch, char *signp)
// {
// 	double tmp;

// 	if (fract)
// 		(void)modf(fract * 10, &tmp);
// 	else
// 		tmp = to_digit(ch);
// 	if (tmp > 4)
// 		for (;; --end) {
// 			if (*end == '.')
// 				--end;
// 			if (++*end <= '9')
// 				break;
// 			*end = '0';
// 			if (end == start) {
// 				if (exp) {	/* e/E; increment exponent */
// 					*end = '1';
// 					++*exp;
// 				}
// 				else {		/* f; add extra digit */
// 				*--end = '1';
// 				--start;
// 				}
// 				break;
// 			}
// 		}
// 	/* ``"%.3f", (double)-0.0004'' gives you a negative 0. */
// 	else if (*signp == '-')
// 		for (;; --end) {
// 			if (*end == '.')
// 				--end;
// 			if (*end != '0')
// 				break;
// 			if (end == start)
// 				*signp = 0;
// 		}
// 	return (start);
// }

// static char *
// exponent(char *p, int exp, int fmtch)
// {
// 	char *t;
// 	char expbuf[MAX_FCONVERSION];

// 	*p++ = fmtch;
// 	if (exp < 0) {
// 		exp = -exp;
// 		*p++ = '-';
// 	}
// 	else
// 		*p++ = '+';
// 	t = expbuf + MAX_FCONVERSION;
// 	if (exp > 9) {
// 		do {
// 			*--t = to_char(exp % 10);
// 		} while ((exp /= 10) > 9);
// 		*--t = to_char(exp);
// 		for (; t < expbuf + MAX_FCONVERSION; *p++ = *t++);
// 	}
// 	else {
// 		*p++ = '0';
// 		*p++ = to_char(exp);
// 	}
// 	return (p);
// }
// #endif /* FLOATINGPT */