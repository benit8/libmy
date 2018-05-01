/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strchr.c
*/

#include "my/string.h"

char *my_strchr(const char *string, char search)
{
	for (; *string; ++string) {
		if (*string == search)
			return ((char *)string);
	}
	return (NULL);
}

char *my_strnchr(const char *string, char search, size_t n)
{
	for (; n--; ++string) {
		if (*string == search)
			return ((char *)string);
	}
	return (NULL);
}

char *my_strrchr(const char *string, char search)
{
	const char *s = string;

	for (; *s; ++s);
	for (; s != string; --s) {
		if (*s == search)
			return ((char *)s);
	}
	return (NULL);
}