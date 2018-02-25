/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memcpy.c
*/

#include "memory.h"

void *mem_cpy(void *dest, const void *src, size_t n)
{
	byte_t *d = dest;
	const byte_t *s = src;

	while (n--)
		*d++ = *s++;
	return (dest);
}