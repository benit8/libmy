/*
** strdup.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 10:34:27 2017 Benoit Lormeau
** Last update Mon Oct 23 10:34:27 2017 Benoit Lormeau
*/

#include "libmy.h"

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