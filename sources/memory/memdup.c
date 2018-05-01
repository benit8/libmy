/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memdup.c
*/

#include "my/memory.h"

void *my_memdup(const void *src, size_t n)
{
	void *mem = my_calloc(n, 1);

	if (mem != NULL)
		my_memcpy(mem, src, n);
	return (mem);
}