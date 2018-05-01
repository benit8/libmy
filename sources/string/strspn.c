/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strspn.c
*/

#include "my/string.h"

size_t my_strspn(const char *str1, const char *str2)
{
	const char *s1 = NULL;
	const char *s2 = NULL;

	for (s1 = str1; *s1; s1++) {
		for (s2 = str2; *s2; s2++) {
			if (*s2 == *s1)
				break;
		}
		if (!*s2)
			break;
	}
	return (s1 - str1);
}

size_t my_strcspn(const char *str1, const char *str2)
{
	const char *s1 = NULL;
	const char *s2 = NULL;

	for (s1 = str1; *s1; s1++) {
		for (s2 = str2; *s2; s2++) {
			if (*s2 == *s1)
				break;
		}
		if (*s2)
			break;
	}
	return (s1 - str1);
}