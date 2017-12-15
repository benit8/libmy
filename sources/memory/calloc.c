/*
** calloc.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Memory
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:39:57 2017 Benoit Lormeau
** Last update Mon Oct 23 09:39:57 2017 Benoit Lormeau
*/

#include "memory.h"

void *my_calloc(size_t n, size_t s)
{
	size_t size = n * s;
	void *p = my_malloc(size);

	if (p != NULL)
		mem_set(p, 0, size);
	return (p);
}