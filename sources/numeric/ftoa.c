/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ftoa.c
*/

#include "my/numeric.h"

static void decimal_part(char *str, size_t i, int precision, int n)
{
	size_t mark = 0;

	str[i++] = '.';
	for (mark = i; n > 0 && precision--; n /= 10)
		str[i++] = (n % 10) + '0';
	while (precision--)
		str[i++] = '0';
	my_strrev(str + mark);
}

char *my_ftoa(double dble, int precision)
{
	char *str = my_calloc(65, sizeof(char));
	int int_part = (int)dble;
	bool neg = (int_part < 0);
	int n = ABS(int_part);
	size_t i = 0;

	for (; n > 0 || i < 1; n /= 10)
		str[i++] = (n % 10) + '0';
	if (neg)
		str[i++] = '-';
	str = my_strrev(str);
	n = (int)my_round((dble - int_part) * my_pow(10, precision));
	if (n == 0 || precision == 0)
		return (str);
	decimal_part(str, i, precision, n);
	return (str);
}