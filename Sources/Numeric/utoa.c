/*
** utoa.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:30:02 2017 Benoit Lormeau
** Last update Tue Nov 14 09:42:08 2017 Benoit Lormeau
*/

#include "Numeric.h"

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