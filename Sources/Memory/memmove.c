/*
** memmove.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Memory
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Fri Nov 10 14:06:44 2017 Benoit Lormeau
** Last update Fri Nov 10 14:06:44 2017 Benoit Lormeau
*/

#include "Memory.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
	uint8_t cpy[n];
	uint8_t *d = dest;
	uint8_t *c = cpy;

	my_memcpy(cpy, src, n);
	while (n--)
		*d++ = *c++;
	return (dest);
}