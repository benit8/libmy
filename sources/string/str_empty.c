/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_empty.c
*/

#include "my/string.h"

bool str_empty(const char *string)
{
	const char *s = string;

	if (!s || *s == '\0')
		return (true);
	for (; *s != '\0'; ++s) {
		if (!is_blank(*s))
			return (false);
	}
	return (true);
}