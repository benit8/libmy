/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_cspn.c
*/

#include "string.h"

ssize_t str_cspn(const char *str1, const char *str2)
{
	const char *s1;
	const char *s2;

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