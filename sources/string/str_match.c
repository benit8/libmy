/*
** str_match.c for Libmy in /mnt/data/Delivery/Perso/Libmy/sources/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Thu Dec 14 10:48:33 2017 Benoit Lormeau
** Last update Thu Dec 14 10:48:33 2017 Benoit Lormeau
*/

#include "string.h"

bool str_match(const char *s1, const char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
		return (str_match(s1 + 1, s2) || str_match(s1, s2 + 1));
	else if (*s1 == '\0' && *s2 == '*')
		return (str_match(s1, s2 + 1));
	else if (*s1 != '\0' && *s1 == *s2)
		return (str_match(s1 + 1, s2 + 1));
	else if (*s1 == '\0' && *s1 == *s2)
		return (true);
	return (false);
}
