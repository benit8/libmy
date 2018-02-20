/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strtol.c
*/

#include "numeric.h"

static
char *strto_get_base(const char *str, int *base)
{
	char *n = (char *)str;

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

long int str_tol(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *n = strto_get_base(str, &base);
	long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*n == '+')
		return (str_tol(n + 1, endptr, base));
	if (*n == '-')
		return (-str_tol(n + 1, endptr, base));
	while ((digit = str_nchr(digits, to_lower(*n++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)n;
	return (res);
}

unsigned long int str_toul(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *n = strto_get_base(str, &base);
	unsigned long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*n == '+')
		return (str_toul(n + 1, endptr, base));
	while ((digit = str_nchr(digits, to_lower(*n++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)n;
	return (res);
}

long long int str_toll(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *n = strto_get_base(str, &base);
	long long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*n == '+')
		return (str_toll(n + 1, endptr, base));
	if (*n == '-')
		return (-str_toll(n + 1, endptr, base));
	while ((digit = str_nchr(digits, to_lower(*n++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)n;
	return (res);
}

unsigned long long int str_toull(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *n = strto_get_base(str, &base);
	unsigned long long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*n == '+')
		return (str_toull(n + 1, endptr, base));
	while ((digit = str_nchr(digits, to_lower(*n++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)n;
	return (res);
}