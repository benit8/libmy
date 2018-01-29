/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_dup.c
*/

#include "string.h"

char *str_dup(const char *src)
{
	size_t len = str_len(src);
	char *dest = my_calloc(len + 1, sizeof(char));

	if (dest != NULL)
		dest = str_ncpy(dest, src, len);
	return (dest);
}

char *str_ndup(const char *src, size_t n)
{
	size_t len = MIN(n, str_len(src));
	char *dest = my_calloc(len + 1, sizeof(char));

	if (dest != NULL)
		dest = str_ncpy(dest, src, len);
	return (dest);
}