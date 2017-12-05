/*
** clear.c for Libmy in /mnt/data/Delivery/Perso/Libmy/Sources/DSA/Queue
**
** Made by Benoit Lormeau
** Login   <benoit.lormeau@epitech.eu>
**
** Started on  Mon Dec 4 11:44:08 2017 Benoit Lormeau
** Last update Mon Dec 4 11:44:08 2017 Benoit Lormeau
*/

#include "DSA/Queue.h"

void Queue_clear(Queue_t *queue)
{
	QueueNode_t *next;

	if (!queue)
		return;
	for (QueueNode_t *curr = queue->head; curr != NULL; curr = next){
		next = curr->next;
		if (queue->cleanUp)
			(queue->cleanUp)(curr->data);
		my_free(curr);
	}
	queue->head = NULL;
}