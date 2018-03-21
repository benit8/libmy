/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memdup.c
*/

#include "my/memory.h"

void *mem_dup(const void *src, size_t n)
{
	void *mem = my_calloc(n, 1);

	if (mem != NULL)
		mem_cpy(mem, src, n);
	return (mem);
}