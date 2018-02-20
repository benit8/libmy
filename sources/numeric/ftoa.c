/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** ftoa.c
*/

#include "numeric.h"

char *my_ftoa(double dble, int precision)
{
	char *str = my_calloc(65, sizeof(char));
	double pow = my_pow(10, precision);
	int intPart = (int)dble;
	int n = intPart;
	size_t mark = 0;
	size_t i = 0;

	for (; n > 0 || i < 1; n /= 10)
		str[i++] = (n % 10) + '0';
	n = (int)my_round((dble - intPart) * pow);
	str = str_rev(str);
	if (n == 0 || precision == 0)
		return (str);
	str[i++] = '.';
	for (mark = i; n > 0 && precision--; n /= 10)
		str[i++] = (n % 10) + '0';
	while (precision--)
		str[i++] = '0';
	str_rev(str + mark);
	return (str);
}