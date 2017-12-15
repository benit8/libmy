/*
** destroy.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/list
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:16:18 2017 Benoit Lormeau
** Last update Mon Dec 4 10:16:18 2017 Benoit Lormeau
*/

#include "dsa/list.h"

void list_destroy(list_t *list)
{
	if (!list)
		return;
	list_clear(list);
	my_free(list);
}