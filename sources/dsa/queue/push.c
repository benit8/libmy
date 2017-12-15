/*
** push.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:46:28 2017 Benoit Lormeau
** Last update Mon Dec 4 11:46:28 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

bool queue_push(queue_t *queue, void *data)
{
	queue_node_t *last;
	queue_node_t *new;

	if (!queue)
		return (false);
	new = my_calloc(1, sizeof(queue_node_t));
	if (!new)
		return (false);
	new->data = data;
	new->next = NULL;
	if (!queue->head)
		queue->head = new;
	else {
		for (last = queue->head; last->next != NULL; last = last->next);
		last->next = new;
	}
	return (true);
}