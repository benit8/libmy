/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_strtoupper.c
*/

#include "my/string.h"

char *my_strtoupper(char *str)
{
	if (!str)
		return (NULL);
	for (char *s = str; *s; ++s)
		*s = to_upper(*s);
	return (str);
}