/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memmove.c
*/

#include "my/memory.h"

void *my_memmove(void *dest, const void *src, size_t n)
{
	byte_t cpy[n];
	byte_t *d = dest;
	byte_t *c = cpy;

	if ((!dest || !src) || n == 0)
		return (NULL);
	my_memcpy(cpy, src, n);
	while (n--)
		*d++ = *c++;
	return (dest);
}