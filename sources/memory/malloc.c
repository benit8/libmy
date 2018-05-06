/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** malloc.c
*/

#include "my/memory.h"

void *my_malloc(size_t size)
{
	void *ptr = NULL;

	if (size == 0)
		return (NULL);
	ptr = malloc(sizeof(size_t) + size);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, &size, sizeof(size_t));
	ptr += sizeof(size_t);
	return (ptr);
}

void my_free(void *ptr)
{
	if (!ptr)
		return;
	free(ptr - sizeof(size_t));
	ptr = NULL;
}

size_t my_malloc_size(const void *ptr)
{
	size_t *size = NULL;

	if (ptr == NULL)
		return (0);
	size = (size_t *)(ptr - sizeof(size_t));
	return (*size);
}