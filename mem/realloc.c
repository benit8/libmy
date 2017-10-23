/*
** realloc.c for libmy in /mnt/data/Delivery/Perso/libmy
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 09:40:27 2017 Benoit Lormeau
** Last update Mon Oct 23 09:40:27 2017 Benoit Lormeau
*/

#include "libmy.h"

void *my_realloc(void *ptr, size_t newSize)
{
	size_t curSize;
	void *newPtr;

	if (ptr == NULL)
		return (my_calloc(1, newSize));
	curSize = my_malloc_size(ptr);
	if (newSize <= curSize)
		return (ptr);
	newPtr = my_calloc(1, newSize);
	my_memcpy(newPtr, ptr, curSize);
	my_free(ptr);
	return (newPtr);
}