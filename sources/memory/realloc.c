/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** realloc.c
*/

#include "my/memory.h"

void *my_realloc(void *ptr, size_t new_size)
{
	size_t cur_size = 0;
	void *new = NULL;

	if (ptr == NULL)
		return (my_calloc(1, new_size));
	cur_size = my_malloc_size(ptr);
	if (new_size <= cur_size)
		return (ptr);
	new = my_calloc(1, new_size);
	if (new == NULL)
		return (NULL);
	my_memcpy(new, ptr, cur_size);
	my_free(ptr);
	return (new);
}