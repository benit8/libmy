/*
** toolbox.c for MyINI in /mnt/data/Delivery/Perso/MyINI/src
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 11 15:06:24 2017 Benoit Lormeau
** Last update Mon Dec 11 15:06:24 2017 Benoit Lormeau
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