/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_match.c
*/

#include "string.h"

bool str_match(const char *str, const char *pat)
{
	if (*str && *pat == '*')
		return (str_match(str + 1, pat) || str_match(str, pat + 1));
	else if (!*str && *pat == '*')
		return (str_match(str, pat + 1));
	else {
		if (*str && *str == *pat)
			return (str_match(str + 1, pat + 1));
		else if (!*str && *str == *pat)
			return (true);
	}
	return (false);
}