/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** itoa.c
*/

#include "my/numeric.h"

char *my_itoa(ssize_t n, uint8_t base)
{
	static char *digits = "0123456789abcdef";
	bool neg = (n < 0);
	char *res;
	size_t i = 0;

	if (!IN_RANGE(base, 2, 16))
		return (NULL);
	res = my_calloc(65, sizeof(char));
	for (i = 0; n != 0 || i < 1; ++i, n /= base)
		res[i] = digits[ABS(n % base)];
	if (neg)
		res[i] = '-';
	return (my_strrev(res));
}