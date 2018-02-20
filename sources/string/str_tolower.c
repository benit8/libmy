/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_tolower.c
*/

#include "string.h"

char *str_tolower(char *str)
{
	if (!str)
		return (str);
	for (char *s = str; *s; ++s)
		*s = to_lower(*s);
	return (str);
}