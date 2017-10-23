/*
** strncat.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 10:56:30 2017 Benoit Lormeau
** Last update Mon Oct 23 10:56:30 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_strncat(char *dest, const char *src, size_t n)
{
	register char *d = dest;
	register const char *s = src;
	size_t dstSiz = my_malloc_size(dest) - 1;
	size_t dstLen = my_strlen(dest);
	size_t srcLen = my_strlen(src);

	if (!n)
		return (dest);
	n = (n > srcLen) ? srcLen : n;
	if (dstSiz - dstLen < n)
		dest = my_realloc(dest, dstLen + n + 1);
	d = dest;
	while (*d != '\0')
		d++;
	while (*s != '\0' && n-- > 0)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}