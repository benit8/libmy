/*
** strtol.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 5 13:29:54 2017 Benoit Lormeau
** Last update Tue Dec 5 13:29:54 2017 Benoit Lormeau
*/

#include "Numeric.h"

static char *strto_get_base(const char **nptr, int *base)
{
	char *n = (char *)*nptr;

	if (IN_RANGE(*base, 2, 36))
		return (n);
	else if (*base == 0){
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
	char *n = strto_get_base(&nptr, &base);
	long int res = 0;
	int index;

	if (!base)
		return (0);
	if (*n == '+')
		return (my_strtol(n + 1, endptr, base));
	if (*n == '-')
		return (-my_strtol(n + 1, endptr, base));
	for (; str_nchr(digits, *n, base); n++){
		index = (int)(str_nchr(digits, *n, base) - digits);
		res = (res * base) + index;
	}
	*endptr = (char *)n;
	return (res);
}

long long int strtoll(const char *nptr, char **endptr, int base);