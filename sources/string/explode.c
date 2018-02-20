/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** explode.c
*/

#include "string.h"

static
bool explode_append(char ***tabp, size_t *sizep, char *token)
{
	char **ntab = my_realloc(*tabp, sizeof(char *) * ((*sizep) + 2));

	if (!ntab)
		return (false);
	ntab[(*sizep)] = str_dup(token);
	if (!ntab[(*sizep)])
		return (false);
	ntab[++(*sizep)] = NULL;
	*tabp = ntab;
	return (true);
}

char **explode(char *original, const char *delim)
{
	size_t tokens = 0;
	char *copy = str_dup(original);
	char *c = copy;
	char *token = str_sep(&copy, delim);
	char **tab = my_calloc(1, sizeof(char *));

	if (!tab)
		return (NULL);
	for (; token != NULL; token = str_sep(&c, delim)) {
		if (!explode_append(&tab, &tokens, token))
			break;
	}
	my_free(copy);
	return (tab);
}