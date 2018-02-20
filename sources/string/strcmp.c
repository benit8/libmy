/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strcmp.c
*/

#include "string.h"

int str_cmp(const char *s1, const char *s2)
{
	for ( ; *s1 == *s2; s1++, s2++)
		if (*s1 == '\0')
			return (0);
	return (*s1 - *s2);
}

int str_ncmp(const char *s1, const char *s2, size_t n)
{
	while (n--) {
		if (*s1++ != *s2++)
			return (*s1 - *s2);
	}
	return (0);
}