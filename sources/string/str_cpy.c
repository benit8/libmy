/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_cpy.c
*/

#include "string.h"

char *str_cpy(char *dest, const char *src)
{
	return (str_ncpy(dest, src, str_len(src)));
}

char *str_ncpy(char *dest, const char *src, size_t n)
{
	char *d = dest;

	while (n > 0 && *src != '\0'){
		*d++ = *src++;
		--n;
	}
	while (n > 0){
		*d++ = '\0';
		--n;
	}
	return (dest);
}