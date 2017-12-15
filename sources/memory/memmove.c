/*
** memmove.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Memory
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Fri Nov 10 14:06:44 2017 Benoit Lormeau
** Last update Fri Nov 10 14:06:44 2017 Benoit Lormeau
*/

#include "memory.h"

void *mem_move(void *dest, const void *src, size_t n)
{
	uint8_t cpy[n];
	uint8_t *d = dest;
	uint8_t *c = cpy;

	mem_cpy(cpy, src, n);
	while (n--)
		*d++ = *c++;
	return (dest);
}