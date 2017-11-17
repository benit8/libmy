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
	char *cpy = my_memdup(src, n);
	register char *d = dest;
	register char *c = cpy;

	if (!cpy)
		return (NULL);
	while (n--)
		*d++ = *c++;
	my_free(cpy);
	return (dest);
}