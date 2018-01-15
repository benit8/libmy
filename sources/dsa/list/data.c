/*
** data.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/list
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:17:41 2017 Benoit Lormeau
** Last update Mon Dec 4 10:17:41 2017 Benoit Lormeau
*/

#include "dsa/list.h"

bool list_push(list_t *list, void *data)
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
	if (!list->head && !list->rear) {
		list->head = new;
		list->rear = new;
		return (true);
	}
	new->prev = list->rear;
	list->rear->next = new;
	list->rear = new;
	return (true);
}

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

void *list_shift(list_t *list)
{
	list_node_t *last;
	void *data;

	if (!list || !list->head)
		return (NULL);
	last = list->rear;
	if (!list->head->next)
		list->head = NULL;
	else
		list->rear->prev->next = NULL;
	list->rear = list->rear->prev;
	data = last->data;
	my_free(last);
	return (data);
}

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
	if (!list->head && !list->rear) {
		list->head = new;
		list->rear = new;
		return (true);
	}
	list->head->prev = new;
	new->next = list->head;
	list->head = new;
	return (true);
}
