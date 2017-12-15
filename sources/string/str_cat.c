/*
** strcat.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 10:54:49 2017 Benoit Lormeau
** Last update Mon Oct 23 10:54:49 2017 Benoit Lormeau
*/

#include "string.h"

char *str_cat(char *dest, const char *src)
{
	char *d = dest;
	const char *s = src;

	for (; *d != '\0'; d++);
	while (*s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (dest);
}

char *str_ncat(char *dest, const char *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	if (!n)
		return (dest);
	for (; *d != '\0'; d++);
	while (*s != '\0' && n-- > 0)
		*d++ = *s++;
	*d = '\0';
	return (dest);
}