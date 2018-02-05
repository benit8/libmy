/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** calloc.c
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