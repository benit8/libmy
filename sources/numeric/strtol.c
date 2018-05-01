/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strtol.c
*/

#include "my/numeric.h"

static char *strto_get_base(const char *str, int *base)
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

long int my_strtol(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *s = strto_get_base(str, &base);
	long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*s == '+')
		return (my_strtol(s + 1, endptr, base));
	if (*s == '-')
		return (-my_strtol(s + 1, endptr, base));
	while ((digit = my_strnchr(digits, to_lower(*s++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)s;
	return (res);
}

unsigned long int my_strtoul(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *s = strto_get_base(str, &base);
	unsigned long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*s == '+')
		return (my_strtoul(s + 1, endptr, base));
	while ((digit = my_strnchr(digits, to_lower(*s++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)s;
	return (res);
}

long long int my_strtoll(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *s = strto_get_base(str, &base);
	long long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*s == '+')
		return (my_strtoll(s + 1, endptr, base));
	if (*s == '-')
		return (-my_strtoll(s + 1, endptr, base));
	while ((digit = my_strnchr(digits, to_lower(*s++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)s;
	return (res);
}

unsigned long long int my_strtoull(const char *str, char **endptr, int base)
{
	static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char *s = strto_get_base(str, &base);
	unsigned long long int res = 0;
	char *digit = NULL;

	if (!base)
		return (0);
	if (*s == '+')
		return (my_strtoull(s + 1, endptr, base));
	while ((digit = my_strnchr(digits, to_lower(*s++), base)) != NULL)
		res = (res * base) + (int)(digit - digits);
	*endptr = (char *)s;
	return (res);
}