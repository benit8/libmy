/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** realloc.c
*/

#include "memory.h"

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
	if (newPtr == NULL)
		return (NULL);
	mem_cpy(newPtr, ptr, curSize);
	my_free(ptr);
	return (newPtr);
}