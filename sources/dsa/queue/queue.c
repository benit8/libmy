/*
** queue.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:41:53 2017 Benoit Lormeau
** Last update Mon Dec 4 11:41:53 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

queue_t *queue_create(clean_func_t *clean_up)
{
	queue_t *queue = my_calloc(1, sizeof(queue_t));

	if (queue){
		queue->head = NULL;
		queue->clean_up = clean_up;
	}
	return (queue);
}

void queue_destroy(queue_t *queue)
{
	if (!queue)
		return;
	queue_clear(queue);
	my_free(queue);
}

void queue_clear(queue_t *queue)
{
	queue_node_t *next;

	if (!queue)
		return;
	for (queue_node_t *curr = queue->head; curr != NULL; curr = next){
		next = curr->next;
		if (queue->clean_up)
			(queue->clean_up)(curr->data);
		my_free(curr);
	}
	queue->head = NULL;
}