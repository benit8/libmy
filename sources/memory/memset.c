/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memset.c
*/

#include "memory.h"

void *mem_set(void *dest, uint8_t c, size_t n)
{
	uint8_t *d = dest;

	if (n > 0 && dest != NULL) {
		while (n--)
			*d++ = c;
	}
	return (dest);
}