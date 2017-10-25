/*
** strcasecmp.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 14:27:11 2017 Benoit Lormeau
** Last update Tue Oct 24 14:27:11 2017 Benoit Lormeau
*/

#include "libmy.h"

int str_casecmp(const char *s1, const char *s2)
{
	for ( ; to_lower(*s1) == to_lower(*s2); s1++, s2++);
	return (*s1 - *s2);
}

int str_ncasecmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	for (; to_lower(*s1) == to_lower(*s2) && --n > 0; s1++, s2++);
	return (*s1 - *s2);
}