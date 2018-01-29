/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memmove.c
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