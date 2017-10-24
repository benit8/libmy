/*
** explode.c for libmy in /mnt/data/Delivery/Perso/libmy/string
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Tue Oct 24 09:34:45 2017 Benoit Lormeau
** Last update Tue Oct 24 09:34:45 2017 Benoit Lormeau
*/

#include "libmy.h"
#include <string.h>

char **explode(const char *delim, char *original)
{
	int tokens = 0;
	char *copy = my_strdup(original);
	char *c = copy;
	char *token = my_strsep(&copy, delim);
	char **tab = my_calloc(1, sizeof(char *));

	if (tab == NULL)
		return (NULL);
	for (; token != NULL; token = my_strsep(&copy, delim)){
		tab = my_realloc(tab, sizeof(char *) * (tokens + 2));
		if (tab == NULL)
			return (NULL);
		tab[tokens++] = my_strdup(token);
	}
	tab[tokens] = NULL;
	my_free(c);
	return (tab);
}