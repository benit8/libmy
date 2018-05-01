/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strapd.c
*/

#include "my/string.h"

char *my_strapd(char *dest, const char *src)
{
	size_t n = my_strlen(src);

	return (my_strnapd(dest, src, n));
}

char *my_strnapd(char *dest, const char *src, size_t n)
{
	char *d = dest;
	const char *s = src;
	size_t dest_size = my_malloc_size(dest) - 1;
	size_t dest_len = my_strlen(dest);

	if (!n)
		return (dest);
	n = MIN(n, my_strlen(src));
	if (dest == NULL)
		return (my_strndup(src, n));
	if (dest_size - dest_len < n)
		dest = my_realloc(dest, dest_len + n + 1);
	for (d = dest; *d; d++);
	while (*s && n--)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}