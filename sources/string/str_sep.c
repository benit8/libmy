/*
** strsep.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 09:49:13 2017 Benoit Lormeau
** Last update Tue Oct 24 11:29:05 2017 Benoit Lormeau
*/

#include "string.h"

char *str_sep(char **stringp, const char *delim)
{
	size_t dLen = str_len(delim);
	char *s = *stringp;
	char *p = NULL;

	if (s == NULL || *s == '\0')
		return (NULL);
	do {
		if (p != NULL)
			s++;
		p = str_str(s, delim);
	} while (p == s);
	if (p == NULL){
		*stringp += str_len(s);
		return (s);
	}
	mem_set(p, 0, dLen);
	*stringp = p + dLen;
	return (s);
}