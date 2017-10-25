/*
** strapd.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Oct 25 11:29:13 2017 Benoit Lormeau
** Last update Wed Oct 25 11:29:13 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_strapd(char *dest, const char *src)
{
	register char *d = dest;
	register const char *s = src;
	size_t dstSiz = my_malloc_size(dest) - 1;
	size_t dstLen = my_strlen(dest);
	size_t srcLen = my_strlen(src);

	if (dstSiz - dstLen < srcLen)
		dest = my_realloc(dest, dstLen + srcLen + 1);
	d = dest;
	for (; *d != '\0'; d++);
	while (*s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (dest);
}