/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strstr.c
*/

#include "my/string.h"

char *my_strstr(char *string, const char *search)
{
	char *a = NULL;
	const char *b = search;

	if (*b == '\0')
		return (string);
	for (; *string != '\0'; string++) {
		if (*string != *search)
			continue;
		a = string;
		for (;; ++a, ++b) {
			if (*b == '\0')
				return (string);
			if (*a != *b)
				break;
		}
		b = search;
	}
	return (NULL);
}

char *my_strnstr(char *string, const char *search, size_t n)
{
	char *a = NULL;
	const char *b = search;

	if (*b == '\0')
		return (string);
	for (; *string != '\0' && n--; string++) {
		if (*string != *search)
			continue;
		if (n < my_strlen(search))
			break;
		a = string;
		for (;; ++a, ++b) {
			if (*b == '\0')
				return (string);
			if (*a != *b)
				break;
		}
		b = search;
	}
	return (NULL);
}