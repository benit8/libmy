/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** malloc.c
*/

#include "memory.h"

void *my_malloc(size_t size)
{
	void *ptr = NULL;

	ptr = malloc(sizeof(size_t) + size);
	if (ptr == NULL)
#ifdef ASSERT_MALLOC
		exit(1);
#else
		return (NULL);
#endif
	mem_cpy(ptr, &size, sizeof(size_t));
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