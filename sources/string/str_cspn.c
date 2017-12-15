/*
** str_cspn.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Dec 12 20:44:31 2017 Benoit Lormeau
** Last update Tue Dec 12 20:44:31 2017 Benoit Lormeau
*/

#include "string.h"

ssize_t str_cspn(const char *str1, const char *str2)
{
	const char *s1;
	const char *s2;

	for (s1 = str1; *s1; s1++) {
		for (s2 = str2; *s2; s2++) {
			if (*s2 == *s1)
				break;
		}
		if (*s2)
			break;
	}
	return (s1 - str1);
}