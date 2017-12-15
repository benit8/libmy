/*
** getSize.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/list
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:17:19 2017 Benoit Lormeau
** Last update Mon Dec 4 10:17:19 2017 Benoit Lormeau
*/

#include "dsa/list.h"

size_t list_get_size(list_t *list)
{
	size_t l = 0;

	for (list_node_t *curr = list->head; curr != NULL; curr = curr->next)
		++l;
	return (l);
}