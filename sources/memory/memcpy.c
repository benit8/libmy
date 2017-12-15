/*
** memcpy.c for memcpy in /mnt/data/Delivery/Perso/libmy/Sources/Memory
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Sep 28 11:38:15 2017 Benoit Lormeau
** Last update Thu Sep 28 11:38:20 2017 Benoit Lormeau
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