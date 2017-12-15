/*
** atou.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 10:30:49 2017 Benoit Lormeau
** Last update Wed Oct 25 10:30:49 2017 Benoit Lormeau
*/

#include "numeric.h"

size_t my_atou(const char *str)
{
	size_t res = 0;

	for (; is_digit(*str); str++)
		res = (res * 10) + (*str - '0');
	return (res);
}