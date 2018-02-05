/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_toupper.c
*/

#include "string.h"

char *str_toupper(char *str)
{
	register char *s = str;

	for (; *s != 0; ++s){
		if (is_lower(*s))
			*s -= 32;
	}
	return (str);
}