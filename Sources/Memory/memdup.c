/*
** memdup.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/Memory
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 11:59:05 2017 Benoit Lormeau
** Last update Mon Oct 23 11:59:05 2017 Benoit Lormeau
*/

#include "Memory.h"

void *my_memdup(const void *src, size_t size)
{
	void *mem = my_calloc(size, 1);

	if (mem != NULL)
		my_memcpy(mem, src, size);
	return (mem);
}