/*
** atoi.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 09:14:53 2017 Benoit Lormeau
** Last update Wed Oct 25 09:14:53 2017 Benoit Lormeau
*/

#include "numeric.h"

ssize_t my_atoi(const char *str)
{
	ssize_t res = 0;

	if (*str == '+')
		return (my_atoi(str + 1));
	if (*str == '-')
		return (-my_atoi(str + 1));
	for (; is_digit(*str); str++)
		res = (res * 10) + (*str - '0');
	return (res);
}