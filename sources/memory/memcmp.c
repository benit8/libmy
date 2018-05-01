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

	while (n--) {
		if (*sa++ != *sb++)
			return (*sa - *sb);
	}
	return (0);
}