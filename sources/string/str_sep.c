/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** str_sep.c
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