/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** utoa.c
*/

#include "numeric.h"

char *my_utoa(size_t n, uint8_t base)
{
	static char *digits = "0123456789abcdef";
	size_t i = 0;
	char *res;

	if (!IN_RANGE(base, 2, 16))
		return (NULL);
	res = my_calloc(65, sizeof(char));
	for (i = 0; n > 0 || i < 1; ++i, n /= base)
		res[i] = digits[n % base];
	return (str_rev(res));
}