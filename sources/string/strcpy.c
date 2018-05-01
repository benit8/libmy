/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strcpy.c
*/

#include "my/string.h"

char *my_strcpy(char *dest, const char *src)
{
	return (my_strncpy(dest, src, my_strlen(src)));
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
	char *d = dest;

	while (n > 0 && *src != '\0') {
		*d++ = *src++;
		--n;
	}
	while (n > 0) {
		*d++ = '\0';
		--n;
	}
	return (dest);
}