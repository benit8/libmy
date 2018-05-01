/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** strsep.c
*/

#include "my/string.h"

char *my_strsep(char **stringp, const char *delim)
{
	size_t d_len = my_strlen(delim);
	char *s = *stringp;
	char *p = NULL;

	if (s == NULL || *s == '\0')
		return (NULL);
	do {
		if (p != NULL)
			s++;
		p = my_strstr(s, delim);
	} while (p == s);
	if (p == NULL) {
		*stringp += my_strlen(s);
		return (s);
	}
	my_memset(p, 0, d_len);
	*stringp = p + d_len;
	return (s);
}