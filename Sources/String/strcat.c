/*
** strcat.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 10:54:49 2017 Benoit Lormeau
** Last update Mon Oct 23 10:54:49 2017 Benoit Lormeau
*/

#include "libmy.h"

char *my_strcat(char *dest, const char *src)
{
	register char *d = dest;
	register const char *s = src;

	for (; *d != '\0'; d++);
	while (*s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (dest);
}