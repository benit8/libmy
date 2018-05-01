/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strtolower.c
*/

#include "my/string.h"

char *my_strtolower(char *str)
{
	if (!str)
		return (str);
	for (char *s = str; *s; ++s)
		*s = to_lower(*s);
	return (str);
}