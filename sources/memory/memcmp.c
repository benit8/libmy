/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** memcmp.c
*/

#include "memory.h"

int mem_cmp(const void *a, const void *b, size_t n)
{
	const char *sa = a;
	const char *sb = b;

	while (n--) {
		if (*sa++ != *sb++)
			return (*sa - *sb);
	}
	return (0);
}