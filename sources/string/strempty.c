/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strempty.c
*/

#include "my/string.h"

bool my_strempty(const char *string)
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