/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_apd.c
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
	size_t dstSiz = my_malloc_size(dest) - 1;
	size_t dstLen = str_len(dest);
	size_t srcLen = str_len(src);

	if (!n)
		return (dest);
	n = MIN(n, srcLen);
	if (dest == NULL)
		return (str_ndup(src, n));
	if (dstSiz - dstLen < n)
		dest = my_realloc(dest, dstLen + n + 1);
	d = dest;
	for (; *d; d++);
	while (*s && n-- > 0)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}