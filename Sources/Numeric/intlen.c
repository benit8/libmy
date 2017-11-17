/*
** intlen.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Numeric
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 09:33:04 2017 Benoit Lormeau
** Last update Wed Oct 25 09:33:04 2017 Benoit Lormeau
*/

#include "Numeric.h"

size_t intlen(ssize_t n)
{
	size_t l = (n < 0) ? 2 : 1;

	for (; n <= -10 || n >= 10; n /= 10, l++);
	return (l);
}

size_t uintlen(size_t n)
{
	size_t l = 1;

	for (; n >= 10; n /= 10, l++);
	return (l);
}