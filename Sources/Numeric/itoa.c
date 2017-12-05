/*
** itoa.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 09:42:44 2017 Benoit Lormeau
** Last update Tue Nov 14 09:41:56 2017 Benoit Lormeau
*/

#include "Numeric.h"

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
	return (str_rev(res));
}