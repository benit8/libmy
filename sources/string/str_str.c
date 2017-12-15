/*
** strstr.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Oct 23 14:17:38 2017 Benoit Lormeau
** Last update Mon Oct 23 14:17:38 2017 Benoit Lormeau
*/

#include "string.h"

char *str_str(char *string, const char *search)
{
	char *a;
	const char *b = search;

	if (*b == '\0')
		return (string);
	for (; *string != '\0'; string++){
		if (*string != *search)
			continue;
		a = string;
		for (;; ++a, ++b){
			if (*b == '\0')
				return (string);
			if (*a != *b)
				break;
		}
		b = search;
	}
	return (NULL);
}

char *str_nstr(char *string, const char *search, size_t n)
{
	char *a;
	const char *b = search;

	if (*b == '\0')
		return (string);
	for (; *string != '\0' && n--; string++){
		if (*string != *search)
			continue;
		if (n < str_len(search))
			break;
		a = string;
		for (;; ++a, ++b){
			if (*b == '\0')
				return (string);
			if (*a != *b)
				break;
		}
		b = search;
	}
	return (NULL);
}