/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strcmp.c
*/

#include "my/string.h"

int my_strcmp(const char *s1, const char *s2)
{
	for ( ; *s1 == *s2; s1++, s2++)
		if (*s1 == '\0')
			return (0);
	return (*s1 - *s2);
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--) {
		if (*s1++ != *s2++)
			return (*s1 - *s2);
	}
	return (0);
}