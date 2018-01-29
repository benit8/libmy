/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** toolbox.c
*/

#include "parsing/ini.h"

size_t tab_size(char **tab)
{
	size_t s = 0;

	for (; tab[s] != NULL; s++);
	return (s);
}

void tab_free(char **tab)
{
	for (size_t i = 0; tab[i] != NULL; ++i)
		my_free(tab[i]);
	my_free(tab);
}