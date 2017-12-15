/*
** pop.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/list
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:22:41 2017 Benoit Lormeau
** Last update Mon Dec 4 10:22:41 2017 Benoit Lormeau
*/

#include "dsa/list.h"

void *list_pop(list_t *list)
{
	list_node_t *first;
	void *data;

	if (!list || !list->head)
		return (NULL);
	first = list->head;
	if (!list->head->next)
		list->rear = NULL;
	else
		list->head->next->prev = NULL;
	list->head = list->head->next;
	data = first->data;
	my_free(first);
	return (data);
}