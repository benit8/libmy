/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_tolower.c
*/

#include "string.h"

char *str_tolower(char *str)
{
	for (char *s = str; *s != 0; ++s){
		if (is_upper(*s))
			*s += 32;
	}
	return (str);
}