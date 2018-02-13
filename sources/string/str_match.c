/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_match.c
*/

#include "string.h"

bool str_match(const char *s1, const char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
		return (str_match(s1 + 1, s2) || str_match(s1, s2 + 1));
	else if (*s1 == '\0' && *s2 == '*')
		return (str_match(s1, s2 + 1));
	else {
		if (*s1 != '\0' && *s1 == *s2)
			return (str_match(s1 + 1, s2 + 1));
		else if (*s1 == '\0' && *s1 == *s2)
			return (true);
	}
	return (false);
}