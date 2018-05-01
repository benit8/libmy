/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strdup.c
*/

#include "my/string.h"

char *my_strdup(const char *src)
{
	size_t len = my_strlen(src);
	char *dest = my_calloc(len + 1, sizeof(char));

	if (dest != NULL)
		dest = my_strncpy(dest, src, len);
	return (dest);
}

char *my_strndup(const char *src, size_t n)
{
	size_t len = my_strnlen(src, n);
	char *dest = my_calloc(len + 1, sizeof(char));

	if (dest != NULL)
		dest = my_strncpy(dest, src, len);
	return (dest);
}