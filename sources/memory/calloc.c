/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** calloc.c
*/

#include "my/memory.h"

void *my_calloc(size_t n, size_t s)
{
	size_t size = n * s;
	void *p = my_malloc(size);

	if (p != NULL)
		my_memset(p, 0, size);
	return (p);
}