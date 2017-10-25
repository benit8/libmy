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

char *my_strdup(const char *src)
{
	size_t len = my_strlen(src);
	char *dest = my_calloc(len + 1, sizeof(char));

	if (dest != NULL)
		dest = my_strncpy(dest, src, len);
	return (dest);
}