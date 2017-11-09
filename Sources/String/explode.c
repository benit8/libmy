/*
** explode.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 09:34:45 2017 Benoit Lormeau
** Last update Tue Oct 24 09:34:45 2017 Benoit Lormeau
*/

#include "String.h"

char **explode(const char *delim, char *original)
{
	int tokens = 0;
	char *copy = str_dup(original);
	char *c = copy;
	char *token = str_sep(&copy, delim);
	char **tab = my_calloc(1, sizeof(char *));

	if (tab == NULL)
		return (NULL);
	for (; token != NULL; token = str_sep(&copy, delim)){
		tab = my_realloc(tab, sizeof(char *) * (tokens + 2));
		if (tab == NULL)
			return (NULL);
		tab[tokens++] = str_dup(token);
	}
	tab[tokens] = NULL;
	my_free(c);
	return (tab);
}