/*
** str_chr.c for libmy in /mnt/data/Delivery/Perso/libmy/Sources/String
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Wed Nov 8 15:35:04 2017 Benoit Lormeau
** Last update Wed Nov 8 15:35:04 2017 Benoit Lormeau
*/

#include "String.h"

char *str_chr(const char *string, char search)
{
	for (; *string; ++string){
		if (*string == search)
			return ((char *)string);
	}
	return (NULL);
}

char *str_nchr(const char *string, char search, size_t n)
{
	for (; *string && n--; ++string){
		if (*string == search)
			return ((char *)string);
	}
	return (NULL);
}

char *str_rchr(const char *string, char search)
{
	const char *s = string;

	for (; *s; ++s);
	for (; s != string; --s){
		if (*s == search)
			return ((char *)s);
	}
	return (NULL);
}