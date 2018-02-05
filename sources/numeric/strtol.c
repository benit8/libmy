/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strtol.c
*/

#include "numeric.h"

static char *strto_get_base(const char *nptr, int *base)
{
	char *n = (char *)nptr;

	if (IN_RANGE(*base, 2, 36))
		return (n);
	else if (*base == 0) {
		if (*n++ != '0'){
			*base = 10;
			return (n);
		}
		if (to_lower(*n) != 'x')
			*base = 8;
		else {
			*base = 16;
			n++;
		}
	}
	else
		*base = 0;
	return (n);
}

long int my_strtol(const char *nptr, char **endptr, int base)
{
	static char digits[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *n = strto_get_base(nptr, &base);
	long int res = 0;
	int index;

	if (!base)
		return (0);
	if (*n == '+')
		return (my_strtol(n + 1, endptr, base));
	if (*n == '-')
		return (-my_strtol(n + 1, endptr, base));
	for (; str_nchr(digits, *n, base); n++) {
		index = (int)(str_nchr(digits, *n, base) - digits);
		res = (res * base) + index;
	}
	*endptr = (char *)n;
	return (res);
}

unsigned long int my_strtoul(const char *nptr, char **endptr, int base)
{
	static char digits[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *n = strto_get_base(nptr, &base);
	unsigned long int res = 0;
	int index;

	if (!base)
		return (0);
	if (*n == '+')
		return (my_strtoul(n + 1, endptr, base));
	for (; str_nchr(digits, *n, base); n++) {
		index = (int)(str_nchr(digits, *n, base) - digits);
		res = (res * base) + index;
	}
	*endptr = (char *)n;
	return (res);
}

long long int my_strtoll(const char *nptr, char **endptr, int base)
{
	static char digits[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *n = strto_get_base(nptr, &base);
	long long int res = 0;
	int index;

	if (!base)
		return (0);
	if (*n == '+')
		return (my_strtoll(n + 1, endptr, base));
	if (*n == '-')
		return (-my_strtoll(n + 1, endptr, base));
	for (; str_nchr(digits, *n, base); n++) {
		index = (int)(str_nchr(digits, *n, base) - digits);
		res = (res * base) + index;
	}
	*endptr = (char *)n;
	return (res);
}

unsigned long long int my_strtoull(const char *nptr, char **endptr, int base)
{
	static char digits[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *n = strto_get_base(nptr, &base);
	unsigned long long int res = 0;
	int index;

	if (!base)
		return (0);
	if (*n == '+')
		return (my_strtoull(n + 1, endptr, base));
	for (; str_nchr(digits, *n, base); n++) {
		index = (int)(str_nchr(digits, *n, base) - digits);
		res = (res * base) + index;
	}
	*endptr = (char *)n;
	return (res);
}