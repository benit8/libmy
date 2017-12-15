/*
** clear.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/dsa/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:44:08 2017 Benoit Lormeau
** Last update Mon Dec 4 11:44:08 2017 Benoit Lormeau
*/

#include "dsa/queue.h"

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