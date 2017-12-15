/*
** clear.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/list
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 10:16:34 2017 Benoit Lormeau
** Last update Mon Dec 4 10:16:34 2017 Benoit Lormeau
*/

#include "dsa/list.h"

void list_clear(list_t *list)
{
	list_node_t *next;

	if (!list)
		return;
	for (list_node_t *curr = list->head; curr != NULL; curr = next){
		next = curr->next;
		if (list->clean_up)
			(list->clean_up)(curr->data);
		my_free(curr);
	}
	list->head = NULL;
	list->rear = NULL;
}