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
	char *s = (char *)str;

	if (IN_RANGE(*base, 2, 36))
		return (s);
	else if (*base == 0) {
		if (*s++ != '0'){
			*base = 10;
			return (s);
		}
		if (to_lower(*s) != 'x')
			*base = 8;
		else {
			*base = 16;
			s++;
		}
	}
	else
		*base = 0;
	return (s);
}

long int str_tol(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *s = strto_get_base(str, &base);
	long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*s == '+')
		return (str_tol(s + 1, endptr, base));
	if (*s == '-')
		return (-str_tol(s + 1, endptr, base));
	while ((digit = str_nchr(digits, to_lower(*s++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)s;
	return (res);
}

unsigned long int str_toul(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *s = strto_get_base(str, &base);
	unsigned long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*s == '+')
		return (str_toul(s + 1, endptr, base));
	while ((digit = str_nchr(digits, to_lower(*s++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)s;
	return (res);
}

long long int str_toll(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *s = strto_get_base(str, &base);
	long long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*s == '+')
		return (str_toll(s + 1, endptr, base));
	if (*s == '-')
		return (-str_toll(s + 1, endptr, base));
	while ((digit = str_nchr(digits, to_lower(*s++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)s;
	return (res);
}

unsigned long long int str_toull(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *s = strto_get_base(str, &base);
	unsigned long long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*s == '+')
		return (str_toull(s + 1, endptr, base));
	while ((digit = str_nchr(digits, to_lower(*s++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)s;
	return (res);
}