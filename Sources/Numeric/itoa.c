/*
** itoa.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 09:42:44 2017 Benoit Lormeau
** Last update Wed Oct 25 09:42:44 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_itoa(ssize_t n)
{
	bool neg = (n < 0);
	size_t i = 0;
	size_t len = intlen(n);
	char *res = my_calloc(len + 1, sizeof(char));

	if (res == NULL)
		return (NULL);
	if (neg)
		len--;
	n = my_abs(n);
	for (i = 0; i < len; ++i){
		res[i] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		res[i] = '-';
	return (str_rev(res));
}