/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ftoa.c
*/

#include "my/numeric.h"

char *my_ftoa(double dble, int precision)
{
	char *str = my_calloc(65, sizeof(char));
	double pow = my_pow(10, precision);
	int int_part = (int)dble;
	int n = int_part;
	size_t mark = 0;
	size_t i = 0;

	for (; n > 0 || i < 1; n /= 10)
		str[i++] = (n % 10) + '0';
	n = (int)my_round((dble - int_part) * pow);
	str = my_strrev(str);
	if (n == 0 || precision == 0)
		return (str);
	str[i++] = '.';
	for (mark = i; n > 0 && precision--; n /= 10)
		str[i++] = (n % 10) + '0';
	while (precision--)
		str[i++] = '0';
	my_strrev(str + mark);
	return (str);
}