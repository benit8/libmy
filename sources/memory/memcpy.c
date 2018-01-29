/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memcpy.c
*/

#include "memory.h"

void *mem_cpy(void *dest, const void *src, size_t len)
{
	uint8_t *d;
	const uint8_t *s;

	d = dest;
	s = src;
	while (len--)
		*d++ = *s++;
	return (dest);
}