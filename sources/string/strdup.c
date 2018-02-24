/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strdup.c
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
	size_t len = str_nlen(src, n);
	char *dest = my_calloc(len + 1, sizeof(char));

	if (dest != NULL)
		dest = str_ncpy(dest, src, len);
	return (dest);
}