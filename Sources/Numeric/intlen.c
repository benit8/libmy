/*
** intlen.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 09:33:04 2017 Benoit Lormeau
** Last update Wed Oct 25 09:33:04 2017 Benoit Lormeau
*/

#include "libmy.h"

size_t intlen(ssize_t n)
{
	size_t l = (n < 0) ? 2 : 1;

	n = (n < 0) ? -n : n;
	for (; n > 10; n /= 10, l++);
	return (l);
}