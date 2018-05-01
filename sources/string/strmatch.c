/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strmatch.c
*/

#include "my/string.h"

bool my_strmatch(const char *str, const char *pat)
{
	if (*str && *pat == '*')
		return (my_strmatch(str + 1, pat) || my_strmatch(str, pat + 1));
	else if (!*str && *pat == '*')
		return (my_strmatch(str, pat + 1));
	else {
		if (*str && *str == *pat)
			return (my_strmatch(str + 1, pat + 1));
		else if (!*str && *str == *pat)
			return (true);
	}
	return (false);
}