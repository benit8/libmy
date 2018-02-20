/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strapd.c
*/

#include "string.h"

char *str_apd(char *dest, const char *src)
{
	size_t n = str_len(src);

	return (str_napd(dest, src, n));
}

char *str_napd(char *dest, const char *src, size_t n)
{
	char *d = dest;
	const char *s = src;
	size_t dest_size = my_malloc_size(dest) - 1;
	size_t dest_len = str_len(dest);

	if (!n)
		return (dest);
	n = MIN(n, str_len(src));
	if (dest == NULL)
		return (str_ndup(src, n));
	if (dest_size - dest_len < n)
		dest = my_realloc(dest, dest_len + n + 1);
	for (d = dest; *d; d++);
	while (*s && n--)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}