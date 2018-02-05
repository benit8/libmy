/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_chr.c
*/

#include "string.h"

char *str_chr(const char *string, char search)
{
	for (; *string; ++string){
		if (*string == search)
			return ((char *)string);
	}
	return (NULL);
}

char *str_nchr(const char *string, char search, size_t n)
{
	for (; n--; ++string){
		if (*string == search)
			return ((char *)string);
	}
	return (NULL);
}

char *str_rchr(const char *string, char search)
{
	const char *s = string;

	for (; *s; ++s);
	for (; s != string; --s){
		if (*s == search)
			return ((char *)s);
	}
	return (NULL);
}