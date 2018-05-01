/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strcasecmp.c
*/

#include "my/string.h"

int my_strcasecmp(const char *s1, const char *s2)
{
	for ( ; to_lower(*s1) == to_lower(*s2); s1++, s2++) {
		if (*s1 == '\0')
			return (0);
	}
	return (to_lower(*s1) - to_lower(*s2));
}

int my_strncasecmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n--) {
		if (to_lower(*s1++) != to_lower(*s2++))
			return (to_lower(*s1) - to_lower(*s2));
	}
	return (0);
}