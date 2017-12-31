/*
** list.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/list
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:10:32 2017 Benoit Lormeau
** Last update Mon Dec 4 10:10:32 2017 Benoit Lormeau
*/

#include "dsa/list.h"

list_t *list_create(void (*clean_up)(void *data))
{
	list_t *list = my_calloc(1, sizeof(list_t));

	if (list) {
		list->head = NULL;
		list->rear = NULL;
		list->clean_up = clean_up;
	}
	return (list);
}

void list_destroy(list_t *list)
{
	if (!list)
		return;
	list_clear(list);
	my_free(list);
}

void list_clear(list_t *list)
{
	list_node_t *next;

	if (!list)
		return;
	for (list_node_t *curr = list->head; curr != NULL; curr = next) {
		next = curr->next;
		if (list->clean_up)
			(list->clean_up)(curr->data);
		my_free(curr);
	}
	list->head = NULL;
	list->rear = NULL;
}