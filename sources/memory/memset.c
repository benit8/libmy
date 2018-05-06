/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memset.c
*/

#include "my/memory.h"

void *my_memset(void *dest, byte_t c, size_t n)
{
	byte_t *d = dest;

	if (!dest || n == 0)
		return (NULL);
	while (n--)
		*d++ = c;
	return (dest);
}