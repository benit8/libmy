/*
** unshift.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/list
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:32:09 2017 Benoit Lormeau
** Last update Mon Dec 4 10:32:09 2017 Benoit Lormeau
*/

#include "dsa/list.h"

bool list_unshift(list_t *list, void *data)
{
	list_node_t *new;

	if (!list)
		return (false);
	new = my_calloc(1, sizeof(list_node_t));
	if (!new)
		return (false);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	if (!list->head && !list->rear){
		list->head = new;
		list->rear = new;
		return (true);
	}
	list->head->prev = new;
	new->next = list->head;
	list->head = new;
	return (true);
}