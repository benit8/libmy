/*
** strnapd.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 11:30:09 2017 Benoit Lormeau
** Last update Wed Oct 25 11:30:09 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_strnapd(char *dest, const char *src, size_t n)
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
	for (; *d != '\0'; d++);
	while (*s != '\0' && n-- > 0)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}