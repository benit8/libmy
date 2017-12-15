/*
** atof.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 12 16:53:50 2017 Benoit Lormeau
** Last update Tue Dec 12 16:53:50 2017 Benoit Lormeau
*/

#include "numeric.h"

static void atof_integer_part(const char **strp, double *res)
{
	char tmp[18];
	ssize_t sz;
	int val;

	sz = str_cspn(*strp, ".");
	if (sz > 0) {
		str_ncpy(tmp, *strp, sz);
		tmp[sz] = '\0';
		val = my_atoi(tmp);
	}
	else
		val = 0;
	*res = (double)val;
	*strp += sz;
}

static void atof_decimal_part(const char **strp, double *res)
{
	const char *str = *strp;
	size_t len;
	int val;
	int div;

	if (*str)
		str++;
	if (*str) {
		len = str_len(str);
		val = my_atoi(str);
		div = 1;
		for (; len > 0; len--)
			div *= 10;
		*res += (double)val / (double)div;
	}
}

double my_atof(const char *str)
{
	double res = 0;

	if (*str == '+')
		return (my_atof(str + 1));
	if (*str == '-')
		return (-my_atof(str + 1));
	atof_integer_part(&str, &res);
	atof_decimal_part(&str, &res);
	return (res);
}