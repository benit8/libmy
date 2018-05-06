/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memcmp.c
*/

#include "my/memory.h"

int my_memcmp(const void *a, const void *b, size_t n)
{
	const byte_t *sa = a;
	const byte_t *sb = b;

	if (n == 0)
		return (0);
	if (!a)
		return (!b ? 0 : -1);
	else if (!b)
		return (1);
	for (; n--; sa++, sb++) {
		if (*sa != *sb)
			return (*sa - *sb);
	}
	return (0);
}