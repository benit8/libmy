/*
** dtoa.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Fri Nov 10 15:39:53 2017 Benoit Lormeau
** Last update Tue Nov 14 09:43:08 2017 Benoit Lormeau
*/

#include "Numeric.h"

char *my_dtoa(double dble, int precision)
{
	char *str = my_calloc(65, sizeof(char));
	double pow = my_pow(10, precision);
	int intPart = (int)dble;
	int n = intPart;
	size_t mark = 0;
	size_t i = 0;

	for (; n > 0 || i < 1; ++i, n /= 10)
		str[i] = (n % 10) + '0';
	n = (int)my_round((dble - intPart) * pow);
	str = str_rev(str);
	if (n == 0 || precision == 0)
		return (str);
	str[i++] = '.';
	for (mark = i; n > 0 && precision--; ++i, n /= 10)
		str[i] = (n % 10) + '0';
	for (; precision--; ++i)
		str[i] = '0';
	str_rev(str + mark);
	return (str);
}