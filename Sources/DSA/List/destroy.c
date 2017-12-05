/*
** destroy.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/List
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:16:18 2017 Benoit Lormeau
** Last update Mon Dec 4 10:16:18 2017 Benoit Lormeau
*/

#include "DSA/List.h"

void List_destroy(List_t *list)
{
	if (!list)
		return;
	List_clear(list);
	my_free(list);
}