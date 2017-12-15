/*
** memset.c for memset in /mnt/data/Delivery/Perso/libmy/Sources/Memory
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Sep 28 11:44:06 2017 Benoit Lormeau
** Last update Thu Sep 28 11:44:06 2017 Benoit Lormeau
*/

#include "memory.h"

void *mem_set(void *dest, uint8_t c, size_t n)
{
	uint8_t *d = dest;

	if (n > 0 && dest != NULL){
		while (n--)
			*d++ = c;
	}
	return (dest);
}