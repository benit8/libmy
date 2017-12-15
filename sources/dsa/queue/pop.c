/*
** pop.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:45:41 2017 Benoit Lormeau
** Last update Mon Dec 4 11:45:41 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

void *queue_pop(queue_t *queue)
{
	queue_node_t *first;
	void *data;

	if (!queue || !queue->head)
		return (NULL);
	first = queue->head;
	queue->head = queue->head->next;
	data = first->data;
	my_free(first);
	return (data);
}